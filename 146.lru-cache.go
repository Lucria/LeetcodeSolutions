/*
 * @lc app=leetcode id=146 lang=golang
 *
 * [146] LRU Cache
 */

// @lc code=start
type Node struct {
	key   int
	value int
	prev  *Node
	next  *Node
}

type LRUCache struct {
	Capacity  int
	head      *Node
	tail      *Node
	valueMaps map[int]*Node
}

func Constructor(capacity int) LRUCache {
	lru := LRUCache{
		Capacity:  capacity,
		head:      new(Node), // These are empty nodes
		tail:      new(Node), // Created just for boundary
		valueMaps: make(map[int]*Node),
	}

	// Making circular doubly linked list
	lru.head.next = lru.tail
	lru.tail.prev = lru.head
	return lru
}

func (this *LRUCache) Get(key int) int {
	if node, ok := this.valueMaps[key]; ok {
		this.setHead(node)
		return node.value
	}
	return -1
}

func (this *LRUCache) Put(key int, value int) {
	if node, ok := this.valueMaps[key]; ok {
		// Key already exists. Update value only and change to most recent
		node.value = value
		this.setHead(node)
	} else {
		// Key doesn't exist. Create new node and check for eviction
		newNode := new(Node)
		newNode.key = key
		newNode.value = value
		this.addNode(newNode)
		if this.Capacity < len(this.valueMaps) {
			// Eviction
			this.deleteTail()
		}
	}
}

func (this *LRUCache) setHead(node *Node) {
	// Setting head is same as deleting the node and reading it back
	this.deleteNode(node)
	this.addNode(node)
}

func (this *LRUCache) deleteTail() {
	// Deletion of tail.
	this.deleteNode(this.tail.prev)
}

func (this *LRUCache) deleteNode(node *Node) {
	// Removes a certain node from the linked list
	// Remove the index from the map
	prev := node.prev
	next := node.next
	prev.next = next
	next.prev = prev

	delete(this.valueMaps, node.key)
}

func (this *LRUCache) addNode(node *Node) {
	node.prev = this.head
	node.next = this.head.next

	this.head.next.prev = node // Needs to account for future nodes added!
	this.head.next = node
	this.valueMaps[node.key] = node
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end

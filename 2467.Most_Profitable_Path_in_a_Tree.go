package main

func mostProfitablePath(edges [][]int, bob int, amount []int) int {

	n := len(amount)
	adjList := make(map[int][]int)

	// building adjList
	for i := 0; i < n; i++ {
		adjList[i] = []int{}
	}

	for _, edge := range edges {
		u, v := edge[0], edge[1]
		adjList[u] = append(adjList[u], v)
		adjList[v] = append(adjList[v], u)
	}

	// map for tracking Bob traversal time
	bobPathTime := make(map[int]int)
	bobVisit := make(map[int]bool)

	bobDFS(adjList, bobPathTime, bobVisit, bob, 0)

	return AliceBFS(adjList, bobPathTime, amount)
}

func AliceBFS(adjList map[int][]int, bobPathTime map[int]int, amount []int) int {
	// make a queue
	queue := make([][3]int, 0)
	queue = append(queue, [3]int{0, 0, 0})

	visit := make(map[int]bool, len(amount))
	maxReward := math.MaxInt * -1

	for len(queue) > 0 {
		// getting the front
		top := queue[0]
		// popping the front
		queue = queue[1:]

		currNode, currTime, currReward := top[0], top[1], top[2]

		// Check for simulation of Alice
		// 1. Alice visit first or bob never visit
		if _, ok := bobPathTime[currNode]; !ok || currTime < bobPathTime[currNode] {
			currReward += amount[currNode]
		} else if currTime == bobPathTime[currNode] {
			// 2. They both reach at the same time
			currReward += amount[currNode] / 2
		}

		if len((adjList[currNode])) == 1 && currNode != 0 {
			maxReward = max(maxReward, currReward)
			visit[currNode] = true
			continue
		}

		for _, neighborNode := range adjList[currNode] {
			if visit[neighborNode] == false {
				queue = append(queue, [...]int{neighborNode, currTime + 1, currReward})
			}
		}
		visit[currNode] = true
	}
	return maxReward
}

func bobDFS(adjList map[int][]int, bobPathTime map[int]int, bobVisit map[int]bool, currNode int, currTime int) bool {

	bobPathTime[currNode] = currTime
	bobVisit[currNode] = true

	// check whether it reach the destination node or not
	if currNode == 0 {
		return true
	}

	for _, neighNode := range adjList[currNode] {
		if !bobVisit[neighNode] {
			if bobDFS(adjList, bobPathTime, bobVisit, neighNode, currTime+1) {
				return true
			}
		}
	}

	// remove it if this not the correct Path
	delete(bobPathTime, currNode)
	return false
}

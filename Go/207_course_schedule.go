/*
*/

func find(source []int, data int) int {
    for index, each := range source {
        if each == data {
            return index
        }
    }
    return -1 
}
func canFinish(numCourses int, prerequisites [][]int) bool {
    in := make(map[int][]int) 
    out := make(map[int][]int)
    visited := make(map[int]bool)
    for i := 0 ; i < numCourses ; i++ {
		in[i] = make([]int,0)
        out[i] = make([]int,0)
	}
    for _, each := range prerequisites {
        in[each[0]] = append(in[each[0]],each[1]) 
        out[each[1]] = append(out[each[1]],each[0]) 
    }
    num := 0 
    for {
        if num == numCourses {
            break 
        } 
        next := -1 
        for i := 0 ; i < numCourses ; i++ {
            if  !visited[i] && len(in[i]) == 0 {
                next = i 
                break 
            }
        }
        if next == -1 {
            return false
        }
        visited[next] = true 
        num++ 
        for _, to := range out[next] {
            index := find(in[to],next)
            in[to] = append(in[to][:index],in[to][index+1:]...) 
        }
    }
    return true
}


/*
*/
var graph [][]bool
var vis []int
func canFinish(numCourses int, prerequisites [][]int) bool {
    graph = make([][]bool,numCourses)
    vis = make([]int,numCourses)
    for i := 0 ; i < numCourses ; i++ {
        graph[i] = make([]bool,numCourses) 
    }
    for _, each := range prerequisites {
        graph[each[1]][each[0]] = true  
    }
    return topoSort() 
}

func topoSort() bool { 
    for i := 0 ; i < len(graph) ; i++ {
        if  vis[i] == 0 {
            if !dis(i) {
                return false 
            }
        } 
    }
    return true 
}

func dis(n int) bool {
    vis[n] = -1 
    for i := 0 ; i < len(graph[n]) ; i++ {
        if !graph[n][i] {
            continue 
        }  
        if vis[i] == -1 {
            return false
        } else if vis[i] == 0 {
            if !dis(i) {
                return false 
            }
        }
    }
    vis[n] = 1 
    return true 
}

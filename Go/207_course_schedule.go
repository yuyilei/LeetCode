
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
/* 
要记录路径。。
*/
func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	var queue [][]string                               // 当队列用。。
	var res [][]string                                 // 存结果路径。。 
	start := []string{beginWord}
	visited := make(map[string]bool)
	visited[beginWord] = true
	queue = append(queue,start)
	has := make(map[string]bool)
	for _, each := range wordList {
		has[each] = true
	}
	for {
		if len(queue) == 0 || len(res) != 0 {
			break
		}
		var newqueue [][]string
		var thisvis []string
		for num, size := 0, len(queue) ; num < size ; num++ {
			now := queue[num]
			lastword := now[len(now)-1]
			for i, w := range lastword {
				for c := 'a' ; c <= 'z' ; c++ {
					if w == c {
						continue
					}
					next := lastword[:i] + string(c) + lastword[i+1:]
					if has[next] && !visited[next] {
						thisvis = append(thisvis,next)                               // thisvis 记录这一层被访问的单词，一层遍历结束之后，再设visited为true。。
						newlist := make([]string,len(now),len(now)+1)
						copy(newlist,now)
                        newlist = append(newlist,next)
						newqueue = append(newqueue,newlist)
						if next == endWord {
							res = append(res,newlist)
						}
					}
				}
			}
		}
		for _, each := range thisvis {
			visited[each] = true
		}
		queue = newqueue
	}
	return res
}
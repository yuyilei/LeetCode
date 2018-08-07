/*
一： 
虽然超时了，但是我用了匿名函数和闭包hhhh
*/
func ladderL·ength(beginWord string, endWord string, wordList []string) int {
    var list []string
    list = append(list,beginWord)
    visited := make(map[string]bool) 
    visited[beginWord] = true
    visnum := 1
    minpath := len(wordList) + 1
    var WordLadder func(list []string) []string
    WordLadder = func(list []string) []string {
        if visnum == len(wordList) || visited[endWord] || len(list) >= minpath {
            if list[len(list)-1] == endWord && len(list) < minpath {
                minpath = len(list)
            }
            return list
        }
        isNext := func(x, y string) bool {
            diff := 0 
            for i := 0 ; diff < 2 && i < len(x) ; i++ {
                if x[i] != y[i] {
                    diff++ 
                }
            }
            if diff != 1 {
                return false
            }
            return true 
        }
        now := list[len(list)-1]
        for _, s := range wordList {
            if visited[s] || !isNext(s,now) {
                continue 
            }
            visited[s] = true
            list = append(list,s) 
            visnum++ 
            list = WordLadder(list) 
            visited[s] = false
            list = list[:len(list)-1]
            visnum--
        }
        return list
    }
    list = WordLadder(list) 
    if minpath == len(wordList) + 1 {
        return 0
    }
    return minpath
} 



/*
二： BFS 
通过，利用 set + queue，go里面没有 set，就用 map， queue用 list  代替
不知都是是go不方便还是我不熟练，没有while真的很难受啊。。 
*/
import "container/list" 
func ladderLength(beginWord string, endWord string, wordList []string) int {
    visited := make(map[string]bool)  // 是否访问过这个单词
    has := make(map[string]bool)      // slice没法查看一个元素是否存在，就用map
    queue := list.New()               // container里面的 list 
    queue.PushBack(beginWord)
    visited[beginWord] = true
    ladder := 1 
    for _, each := range wordList {
        has[each] = true
    }
    for {
        if queue.Len() == 0 {
            break
        }
        ladder++ 
        for num, size := 0, queue.Len()  ; num < size ; num++ {
            top := queue.Front()
            queue.Remove(top)
            now := top.Value.(string)
            for i, w := range now {
                for c := 'a' ; c <= 'z' ; c++ {
                    if w == c {
                        continue 
                    }
                    next := now[:i] + string(c) + now[i+1:]
                    if has[next] && !visited[next] {
                        if next == endWord {
                            return ladder 
                        }
                        queue.PushBack(next)
                        visited[next] = true 
                    }
                }
            }
        }
    }
    return 0
}

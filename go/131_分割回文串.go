package main

import "fmt"

func isPartition(s string) bool {
	strLen := len(s)
	st := 0
	ed := strLen-1
	for st<ed{
		if s[st]!=s[ed]{
			return false
		}
		st++
		ed--
	}
	return true
}

func recur(res *[][]string, curRes []string, s string)  {
	if s==""{
		*res = append(*res, curRes)
		return
	}
	for i:=0;i<len(s);i++{
		frontString := s[:i+1]
		tailString := s[i+1:]
		if !isPartition(frontString){
			continue
		}
		temp := make([]string, len(curRes))
		copy(temp, curRes)
		/* 这两句相当于深拷贝了, 如果没有这两句使用下面的一句
		temp = append(curRed, frontString)  当第二次循环的时候curRes还是以前的, 在后面加上了另一个string
		会导致上一个temp []string 改变
		Ex:
		curRes: [1,2]
		temp 第一次加3 [1,2,3]
		第二次的时候, 因为curRes还是原来的, 比如加4, temp中的3, 变成了4
		 */
		temp = append(temp, frontString)
		recur(res, temp, tailString)
	}
}
func partition(s string) [][]string {
	var res [][]string
	var curRes []string
	recur(&res, curRes, s)
	return res
}

func main() {
	s := "abababb"
	res := partition(s)
	for _, v := range res {
		fmt.Println(v)
	}
}

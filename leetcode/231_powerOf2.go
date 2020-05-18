// Given an integer, write a function to determine if it is a power of two.
package main

import "fmt"

//func isPowerOfTwo(n int) bool {
//	init := 1
//	for init<n{
//		init*=2
//	}
//
//	if init==n{
//		return true
//	}else {
//		return false
//	}
//}

func isPowerOfTwo(n int) bool {
	return n>0&&n&(n-1)==0
}

func main() {
	res := isPowerOfTwo(127)
	fmt.Println(res)
}
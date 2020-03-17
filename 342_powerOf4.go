// Given an integer, write a function to determine if it is a power of two.
package main

import "fmt"

func isPowerOfFour(n int) bool {
	init := 1
	for init<n{
		init*=4
	}

	if init==n{
		return true
	}else {
		return false
	}
}

func main() {
	res := isPowerOfFour(64)
	fmt.Println(res)
}
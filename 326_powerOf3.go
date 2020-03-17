// Given an integer, write a function to determine if it is a power of two.
package main

import "fmt"

func isPowerOfThree(n int) bool {
	init := 1
	for init<n{
		init*=3
	}

	if init==n{
		return true
	}else {
		return false
	}
}

func main() {
	res := isPowerOfThree(27)
	fmt.Println(res)
}
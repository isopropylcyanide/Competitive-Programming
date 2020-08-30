package main

import "fmt"

func main() {
    defer fmt.Println(factorial(10))
    fmt.Println("hello world")
}

func factorial(num int) int{
    if (num == 0){
        return 1
    }
    return num * factorial(num - 1)
}

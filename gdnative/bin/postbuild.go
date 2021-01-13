package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

// Check for errors.
func checkErr(err error) {
	if err != nil {
		log.Fatal(err)
	}
}

// Copies over a file from the src to a dest.
func copyFile(srcFilePath string, destFilePath string) {
	data, err := ioutil.ReadFile(srcFilePath)
	checkErr(err)

	// Write data to the destination.
	err = ioutil.WriteFile(destFilePath, data, 0644)
	checkErr(err)
}

// Start our application.
func main() {
	filePathSrc := flag.String("src", "./../gdnative/builds/debug/GodotProjectLib.dll", "file src path")
	filePathDest := flag.String("dest", "./../project/libs/win64/GodotProjectLib.dll", "file dest path")

    fmt.Println("attempting to move " + *filePathSrc + " to " + *filePathDest)

	if _, err := os.Stat(*filePathSrc); !os.IsNotExist(err) {
		fmt.Println("moving postbuild dll files from " + *filePathSrc + " to " + *filePathDest)
		copyFile(*filePathSrc, *filePathDest)
	} else {
	    fmt.Println("unable to move files!");
	}
}

package main

import (
	"fmt"
	"strings"

	uuidlib "github.com/google/uuid"
)

// idLengthLimit is the max length limit for the ID (library internal)
const idLengthLimit = 12

// GenerateUniqueID generates a unique ID using a one way function on a new UUID
func GenerateUniqueID() (string, error) {
	uuid := uuidlib.New()
	uuidStr := strings.Replace(uuid.String(), "-", "", -1) // replace hyphens
	uuidStr = uuidStr[(len(uuidStr) - idLengthLimit):]     // trim to the desired limit
	return strings.ToUpper(uuidStr), nil                   // upper case
}

func main() {
	for i := 0; i < 10; i++ {
		if id, err := GenerateUniqueID(); err == nil {
			fmt.Printf("Generated ID %s\n", id)
		}
	}
}

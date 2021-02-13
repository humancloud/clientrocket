package main

import (
	"encoding/json"
	"fmt"
	"net"
)

const (
	ADDRESS = "127.0.0.1:8888"
)

type Login struct {
	login string
}

func main() {
	conn, _ := net.Dial("tcp", ADDRESS)

	defer conn.Close()

	login := `{"User":1,"Name":"lu","Passwd":"123"}`
	result := make([]byte, 1024)
	conn.Write([]byte(login))
	n, _ := conn.Read(result)
	var in Login
	json.Unmarshal(result[0:n], &in)
	fmt.Println(in.login)

	buf := `{"Messtype":0,"Srcid":1,"Destid":2,"Strmess":"helloworld"}`
	conn.Write([]byte(buf))
}

package main

import (
	"encoding/json"
	"fmt"
	"net"
)

const (
	ADDRESS = "127.0.0.1:8888"
)

type ChatMess struct {
	Messtype int
	Srcid    int
	Destid   int
	Strmess  string
}

type Login struct {
	Login string
}

func main() {
	conn, _ := net.Dial("tcp", ADDRESS)

	defer conn.Close()

	//登录
	login := `{"User":2,"Name":"li","Passwd":"123"}`
	result := make([]byte, 1024)
	conn.Write([]byte(login))
	n, _ := conn.Read(result)
	var in Login
	json.Unmarshal(result[0:n], &in)
	fmt.Printf("%s\n", string(result)[0:n])
	fmt.Println(in.Login)

	b := make([]byte, 512)
	logout := `{"Messtype":4,"User":2,"Name":"li"}`
	conn.Write([]byte(logout))
	n, _ = conn.Read(b)
	fmt.Printf("%s", string(b[0:n]))
	return

	//接收数据
	buf := make([]byte, 1024)
	n, _ = conn.Read(buf)

	var chat ChatMess
	json.Unmarshal(buf[0:n], &chat)

	fmt.Println(chat)
}

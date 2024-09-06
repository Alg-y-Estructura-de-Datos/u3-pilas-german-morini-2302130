package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strings"
)

var (
	DOC_NAME = "Ej7_content.txt"
	STAR     = map[bool]string{
		true:  "\033[33m*\033[0m",
		false: "",
	}
)

type Nodo[T any] struct {
	dato      T
	siguiente *Nodo[T]
}

func (n *Nodo[T]) GetDato() T {
	return n.dato
}

func (n *Nodo[T]) GetSiguiente() *Nodo[T] {
	return n.siguiente
}

type Pila[T any] struct {
	final *Nodo[T]
}

func (p *Pila[T]) String() string {
	var aux = &Pila[T]{}
	var content string
	var tmp T

	for !p.IsEmpty() {
		tmp, _ = p.Pop()
		aux.Push(tmp)
	}

	for !aux.IsEmpty() {
		tmp, _ := aux.Pop()
		p.Push(tmp)
		content += fmt.Sprintf("%v\n", tmp)
	}

	return content
}

func (p *Pila[T]) Pop() (T, error) {
	var dato T

	if p.final == nil {
		return dato, errors.New("pila vacia")
	}

	dato = p.final.dato
	p.final = p.final.siguiente

	return dato, nil
}

func (p *Pila[T]) Push(dato T) {
	var nuevo *Nodo[T] = &Nodo[T]{dato, p.final}
	p.final = nuevo
}

func (p *Pila[T]) IsEmpty() bool {
	return p.final == nil
}

func Guardar(txt *Pila[string]) error {
	file, err := os.OpenFile(DOC_NAME, os.O_CREATE|os.O_WRONLY|os.O_TRUNC, 0644)
	if err != nil {
		return err
	}

	_, err = file.WriteString(txt.String())
	if err != nil {
		return err
	}

	file.Close()
	return nil
}

func Cargar() (*Pila[string], error) {
	file, err := os.OpenFile(DOC_NAME, os.O_RDONLY|os.O_CREATE, 0644)
	if err != nil {
		return nil, err
	}
	var scanner = bufio.NewScanner(file)
	var txt *Pila[string] = &Pila[string]{}

	for scanner.Scan() {
		txt.Push(scanner.Text())
	}

	file.Close()
	return txt, nil
}

func main() {
	var input string
	var parts []string
	var scanner = bufio.NewScanner(os.Stdin)
	var modificado = false

	texto, err := Cargar()
	if err != nil {
		fmt.Println("\033[31m[Fatal]\033[0mno se pudo cargar el archivo")
		os.Exit(2)
	}

	fmt.Print("\033[H\033[2J") // limpia la terminal
	for {
		fmt.Printf("\033[34mMicrosoft Word™\033[0m: %s\n%v\n\n\n\033[32m>\033[0m ", DOC_NAME+STAR[modificado], texto.String())

		scanner.Scan()
		input = scanner.Text()
		if err := scanner.Err(); err != nil {
			fmt.Println("\033[31m[Err]\033[0m vuelva a ingresar un comando")
			fmt.Println(err)
			continue
		}

		parts = strings.Split(input, " ")

		fmt.Print("\033[H\033[2J")
		switch parts[0] {
		case "escribir":
			texto.Push(strings.Join(parts[1:], " "))
			modificado = true
		case "borrar":
			_, err := texto.Pop()
			if err != nil {
				fmt.Println("\033[31m[Err]\033[0m no hay nada escrito")
				continue
			}
			modificado = true
		case "recargar":
			texto, err = Cargar()
			if err != nil {
				fmt.Println("\033[31m[Fatal]\033[0m no se pudo cargar el archivo")
				os.Exit(2)
			}
			modificado = false
		case "guardar":
			Guardar(texto)
			modificado = false
		case "salir":
			if modificado {
				fmt.Println("Ha modificado el documento")
				fmt.Println("¿Desea guardar los cambios? [S:n]")
				fmt.Scan(&input)

				if input == "S" {
					Guardar(texto)
				}
			}
			return
		default:
			fmt.Println("\033[31m[Err]\033[0m comando desconocido, vuelva a introducir un comando valido:")
			fmt.Println("    escribir 'PALABRA'")
			fmt.Println("    borrar")
			fmt.Println("    recargar")
			fmt.Println("    guardar")
			fmt.Println("    salir")
		}
	}
}

# INCLUDE FORT

*"Um forte espetacular, dizem que possui um conjunto de bibliotecas em seu interior que até hoje nenhum ser 
humano conseguiu contar quantos livros há naquele local. Os grandes estudiosos vivem apenas para apreciar 
a vastidão de conhecimento que existe dentro desse forte blindado de conhecimento. Todos remetem a essa 
velha construção em algum momento de suas vidas. Afinal, conhecimento nunca é demais."* <br>

## Função

A linguagem C++ possui o incrível fator de importar bibliotecas ao nosso código. Como? Utilizando a função include.
Mas porque importar bibliotecas? Qual a sua utilidade?
Um velho meistre que a muito tempo vive no forte include responde: o conhecimento do mundo é vasto, mas o ser humano
é incapaz de obter tudo de uma só vez. Para isso, utilizamos a função include que importa bibliotecas ao nosso código.
Ela nos poupa de muita programação. Uma vez que uma função esteja presente em uma biblioteca, basta importar a 
biblioteca para nosso código e utilizarmos a função, sem uma necessidade de implementá-la. <br>

## Como fazemos a importação?

O velho meistre do forte o olha com um sorriso no rosto, percebendo o poder da curiosidade e a busca do conhecimento
de um jovem programador e responde: basta utilizarmos o caractere ‘#’ somado da palavra include. Entre < > colocamos
o nome da biblioteca a ser chamada.<br>

Por exemplo, a famosa biblioteca que muito utilizamos:<br>

**#include <iostream'>**

Ou até mesmo se precisamos do vasto conhecimento dado pela matemática podemos utilizar facilmente suas funções, 
importando a biblioteca:<br>

**#include <math.h>**
```
#include <math.h>
#include <stdio.h>

int main(void)
{
  for(int i = 1; i < 5; i++)
    printf("pow(3.2, %d) = %lf\n", i, pow(3.2, i));  
  return 0;
}
 ```

A função **pow** é uma função especifica da bilbioteca math.h que foi importada para o nosso código

## Apenas bibliotecas podem ser importadas?

Não, podemos importar no nosso código outros códigos. Sim, nem todos os livros contém tudo que você precisa, certo?
Assim, podemos pegar vários códigos e importa-los a um código main. Como? Muito simples. A mesma função include, 
mas o nome do código está entre “ ”. Assim, podemos usar funções de outros códigos em nosso código main, como se
fossem bibliotecas feitas por nós mesmos. Incrível não?

**#include “codigo.h”**
 
Por exemplo, podemos ter um código chamado "add.cpp" apenas com uma função

```
int add(int x, int y)
{
    return x + y;
}
 ```
 E podemos importar esse código para nosso arquivo main, utilizando a função implementeada em " add.cpp"
 
```
#include <iostream>
#include "add.h"
 
int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
    return 0;
}
```

Após esta explicação, o velho meistre acariciando sua longa barba diz: sempre que buscar conhecimento, volte aqui no forte. Tudo que precisar estará aqui e eu ajudarei sempre que possível. Se ainda lhe surgir dúvidas sobre como funciona nossas bibliotecas, procure
nosso guia que está sempre sentado em uma cadeira na entrada do forte. Uma pena que ele está sempre cochilando, mas dê uma insistida no assunto que ele lhe ajudará. Aqui está a localização deste guia:

[Guia do forte](http://www.cplusplus.com/)<br>

[The C++ Lands](https://drive.google.com/file/d/0B3DUpmL8tTt8N2JIRklJeTIxYW8/view)

# DATA STRONGHOLD

*"Uma grande cidadela surge a vista na grande planície adiante. Pode-se perceber de longe que ela é extremamente fortificada,
onde jamais alguém conseguiria conquista-la com facilidade. Vários cercos foram feitos em volta desta incrível estrutura, 
mas nada consegui vencê-la. Os mais velhos dizem que ela é imbatível e que nunca mudou, manteve-se sempre com a mesma política.
Ao seu lado encontra-se a imensa floresta da herança múltipla. No limite da visão, ao final da floresta encontra-se em destaque,
crescendo em meio ao horizonte, tentando atingir as nuvens, a incrível torre de Bjarne Stroustrup."*

## DIVISÃO SOCIAL

Tudo dentro da cidadela sempre foi de certa forma “organizada”. A idade média de fato é um período em que poucos possuem muito, 
e muitos possuem pouco. A divisão da cidade se divide em 3 partes: 

Em inferioridade, mas com poderio excessivo encontra-se os nobres, que se escondem dentro de seus altos castelos, 
e pouco possuem contato com o povo. Podemos nos referir aos nobres como **PRIVADOS**.

No segundo patamar temos o clero, que possui grande força política, e inclusive tem acesso aos nobres, muitas vezes lhes 
aconselhando sobre diversos assuntos e principalmente utilizando de seus recursos. Podemos nos referir ao clero como **PROTECTED**,
afinal os nobres juram fiel liberdade e proteção as homens de deus. Assim como o clero possui influencia dentro da vida dos nobres,
eles influenciam fortemente o povo. Podemos dizer que o povo tem contato apenas com as ideias da nobreza, que são trazidas pelo clero.
Pelo fato da nobreza ser muito privada, o clero que vive diariamente com o povo, escutando suas preces e lhes dando o que for 
necessário, visto que os nobres não lhes dão nada.

Na parte mais inferior encontrasse o povo. Aqueles que lutam contra a fome todos os dias. Aqueles que enfrentam o medo batendo em 
suas portas. Aqueles que não tem nada, mas que continuam levando a vida de suas humildes formas, ajudando uns aos outros, pois tudo
o que é criado vai para os nobres e o clero, sobrando apenas a miséria ao grande povo. Podemos chamar esse imenso povo como **PUBLIC**. 
Grande parte da população da cidade concentra-se nesta parte inferior, onde todos os métodos restantes são criados. 
Esse grande povo é o responsável por movimentar a cidade, por mais que recebam misérias por isso.

## FUNÇÃO

Com o intuito de organizarmos nosso código, dividimos nossas classes em alguns aspectos. Podemos ter 3 tipos: Private, Protected e Public.

### Private

A ideia de utilizarmos Private, é como o próprio nome diz, nos limitarmos a alguma coisa. 
Apenas métodos dentro da mesma classe podem utilizar os tipos privados. Se buscarmos esses dados diretos, encontramos erros. 

É necessário criarmos métodos que nos deem acesso a esses dados. Podemos declarar várias “funções” de retorno em nosso código que nos
dão acesso a estes dados.

### Protected

Ao utilizarmos as formas protected, tornamos os atributos e métodos visíveis as classes derivadas, que utilizam do mesmo atributo da classe principal. Por exemplo, se tivermos uma classe principal chamada pessoa, e colocarmos o atributo nome como protected, qualquer classe que criarmos que herdar da classe pessoa, poderá utilizar seus atributos. Uma classe estudante também é considerada uma pessoa, e assim também possui um nome. Fazemos isso para reaproveitar partes do código, e deixa-lo mais organizado. Vale destacar que apenas classes derivadas conseguem herdar os atributos, classes que não possuem nenhum tipo de herança não encontram os devidos atributos. As famílias da cidadela eram bem restritas.

```
class Person{
protected:
  string name;
pulbic:
  Person();
  ...
  
};

class Student: public Person{
  string course;
public:
  Student(){
  ...
  name = "";      //OK!
  }
};
```

Podemos perceber que a classe Student herda o atributo da classe Person, e pode utilizar esse atributo como achar necessário, devido ao fato de ser protected.

### Public

O próprio nome já diz. Por ser público, todos possuem acesso. Podemos buscar dados que forem públicos de uma classe mesmo fora dela. Podemos buscar esses valores nos atributos da classe e podemos usá-los nas nossas funções, manipulando como quisermos. Podemos chamar métodos públicos na nossa função main que iremos obter todos os resultados possíveis.

```
class Circle{
private:
  float x;
  float y;
  float z;
public:
  float area(){
    return 3.14168*r*r;
  }
};

int main(){
  Circle c;
  
  c.area();     //OK! area é publico, temos acesso
  c.x = 0;      //ERRO! x é privado, não temos acesso
}
```
Podemos perceber a diferença. Temos acesso a área do círculo, pois esta é pública, mas ao tentarmos acessar o atributo X, somos barrados, pois ser do tipo private.

Se existe alguma dúvida a respeito de heranças e como elas funcionam, faça uma visita a Floresta da Herança que encontra-se no extremo oeste do nosso mapa, mas aqui está um caminho que eu mesmo descobri que pode leva-lo até a floresta em questão de segundos!

- [Inheritance Forest](https://github.com/Shurtugall/Paradigmas/blob/master/extras/c%2B%2Blands4.md)

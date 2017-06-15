# INHERITANCE FOREST

*"Rodeada de montanhas a sua volta, surge a floresta da herança. Uma floresta muito velha, onde seres vagam por entre suas arvores, mas poucos sabem sobre o que um dia aconteceu naquela região. Dizem que Ents vivem na floresta, os famosos pastores das árvores, aqueles que protegem a floresta de todo o mal que tenta entrar em seu domínio. Mas a muito tempo ninguém adentra seus domínios, dizem que a floresta é amaldiçoada e se distanciam o quanto podem. Os únicos que se aventuram por entre suas árvores são alguns elfos que vão em busca de conhecimento. A última visita que se teve notícia na floresta foi quando dois pequeninos adentraram seu perímetro e fizeram uma grande confusão. Mostraram o que foi feito no sul da floresta pelo mago branco, a destruição de grande parte da floresta, o que resultou na última marcha dos ents contra o mago da torre. Hoje em dia, nada mais se soube da floresta. Apenas acredita-se que diversos descendentes dos Ents cresceram e muitas arvores permanecem de pé depois de tanto tempo."*

## HERANÇA

A ideia de usarmos herança em c++ leva-se ao fato de que diversas vezes criamos classes com os atributos semelhantes. Por exemplo, podemos criar uma classe chamada Pessoa que possui nome, idade, CPF, cor dos olhos, etc. Também podemos criar outra classe chamada Estudante que teria também como atributos nome, idade, CPF, e diversos outros atributos que podem ou não ser semelhantes ao de outra classe. Com o intuito de reaproveitarmos o código e interligarmos as classes utilizamos o fator de herança. Mas como funciona a Herança?

Vamos supor que tenhamos uma sequência de arvores da nossa floresta. Podemos classifica-las em Gimnospermas ou Angiospermas como estuda a biologia. As Gimnospermas não possuem frutos, utilizam de grande parte de sementes e são geralmente de grande estatura. As Angiospermas possuem frutos e possuem tamanhos variados.Com isso, podemos classificar cada arvore que encontrarmos na nossa floresta como um dos dois tipos. Logo, ao invés de criarmos uma classe pinheiro e outra araucária, com os mesmos atributos, criamos as duas classes que apenas herdam os atributos de uma classe principal chamada Gimnospermas.

Assim podemos reaproveitar o código, sem falar na simplicidade e organização que criamos. A palavra-chave é *REUSO*.

```
class Gimnospermas{
protected:
    string atributo1;
    int tamanho;
    int idade;
public:
    Gimnospermas(){
        ...
    }
};

class Pinheiro: public Gimnospermas{
public:
    Pinheiro(){
        atibuto1 = "folhas";
        tamanho = 100;
        idade = 10;
    }
};
```

Veja que podemos usar os atributos de Gimnospermas na classe pinheiro, pois herdamos todos eles da classe mãe. Desse modo podemos reutilizar o código.

## RELAÇÕES

### IS-A

A relação Is-a refere-se ao fato de podemos dizer: um estudante é uma pessoa, mas nem toda pessoa é um estudante. É utilizado no conceito de generalização/especialização.

```
int main(){
  Person p;
  Student s;
  vector<Person*> v;
  v.push_back(&p);
  v.push_back(&s);
}
```
Veja que, se ao invés de criarmos um vetor do tipo Person, mas sim do tipo Student, ao executarmos a linha de push back de p, estariamos colocando uma pessoa dentro do vetor de estudantes, mas essa pessoa poderia não ser um estudante.

### HAS-A

A relação Has-a refere-se ao fato de que podemos de dizer: uma pessoa tem um carro. É utilizado no conceito de agregação/composição

```
Class Person{
	Car c;
};
```

Podemos perceber que a classe pessoa pode possuir um carro da classe Car. A diferença a ser observada é que uma pessoa pode ter um carro, mas ao contrário não pode ter um estudante, pois a classe estudante herda atributos da classe pessoa. Logo pode ser considerada uma pessoa também. A ideia de posse não entra nesse caso.

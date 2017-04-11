%   Call (8) azulejos(120, _584)  creep		Chama a fun��o passando 120 e a variavel _584
%   Call (9) 1200  creep				Verifica se 120  0
%   Exit (9) 1200  creep				Sucesso!
%   Call (9) _810 is floor(sqrt(120))  creep  	Variavel _810 recebe raiz quadrada de 120
%   Exit (9) 10 is floor(sqrt(120))  creep    	Sucesso!
%   Call (9) _822 is 120-1010  creep			_822 recebe 120-1010
%   Exit (9) 20 is 120-1010  creep			Sucesso!
%   Call (9) azulejos(20, _824)  creep		Chama a fun��o passando 20 e a variavel _824 como par�metro
%   Call (10) 200  creep				Verifica se 20  0
%   Exit (10) 200  creep				Sucesso!
%   Call (10) _830 is floor(sqrt(20))  creep		_830 recebe raiz quadrada de 20
%   Exit (10) 4 is floor(sqrt(20))  creep		Sucesso!
%   Call (10) _842 is 20-44  creep			_842 recebe 20-44
%   Exit (10) 4 is 20-44  creep			Sucesso!
%   Call (10) azulejos(4, _844)  creep		Chama a fun��o passando 4 e a vari�vel 844 como par�metro
%   Call (11) 40  creep				Verifica se 4  0
%   Exit (11) 40  creep				Sucesso!
%   Call (11) _850 is floor(sqrt(4))  creep		_850 recebe raiz quadrada de 4
%   Exit (11) 2 is floor(sqrt(4))  creep		Sucesso!
%   Call (11) _862 is 4-22  creep			_862 recebe 4-22
%   Exit (11) 0 is 4-22  creep			Sucesso!
%   Call (11) azulejos(0, _864)  creep		Chama a fun��o passando 0 e a vari�vel _864 como par�metro
%   Exit (11) azulejos(0, 0)  creep			Fun��o com os par�metros 0 e 0
%   Call (11) _868 is 1+0  creep			_862 recebe 1 + 0
%   Exit (11) 1 is 1+0  creep				Sucesso!
%   Exit (10) azulejos(4, 1)  creep			Logo, fun��o com par�metros (4, 1)
%   Call (10) _874 is 1+1  creep			_874 recebe 1+1
%   Exit (10) 2 is 1+1  creep				Sucesso!
%   Exit (9) azulejos(20, 2)  creep			Azulejos passa com par�metros(20, 2)
%   Call (9) _584 is 1+2  creep			_584 recebe 1+2
%   Exit (9) 3 is 1+2  creep				Sucesso!
%   Exit (8) azulejos(120, 3)  creep			Fun��o com parametros (120, 3)
%	A = 3 ;						A(valor a ser procurado) � 3
%   Redo (11) azulejos(0, _1380)  creep		Procura outras solu��es
%   Call (12) 00  creep				Verifica se 0  0
%   Fail (12) 00  creep				Falha! O programa n�o encontrou outras solu��es


% 3. Escolha algum predicado recursivo que esteja nos slides ou em qualquer outra fonte. Fa�a a execu��o passo-a-passo de 
%uma consulta com o predicado escolhido. Lembre-se de mostrar o c�digo do predicado no seu arquivo

ultimo([H],H).
ultimo([_  T], U) -
ultimo(T,U).

%Valor passado ([1,2,3],X)

%		Trace output					Coment�rio
%   [trace]  - sum([1,2,3],X).				Chama a fun��o passando a lista [1,2,3] e a vari�vel X
%   Call (8) sum([1, 2, 3], _602)  creep		Reconhece X como a vari�vel _602
%   Call (9) sum([2, 3], _838)  creep			Percorre o la�o retirando o primeiro elemento da lista e armazenando
%   Call (10) sum([3], _838)  creep			Percorre o la�o e retira o segundo elemento
%   Call (11) sum([], _838)  creep			Percorre o la�o e retira o terceiro elemento
%   Exit (11) sum([], 0)  creep			Verifica que a lista � vazia e por isso n�o � poss�vel a retirada, condi��o de parada
%   Call (11) _842 is 3+0  creep			A vari�vel _842 verifica a soma de 3+0 
%   Exit (11) 3 is 3+0  creep				Sucesso!
%   Exit (10) sum([3], 3)  creep			Retorna a lista, percorrendo ao contr�rio somando cada elemento por vez
%   Call (10) _848 is 2+3  creep			_848 recebe 2(segundo elemento da lista) + 3(terceiro elemento que foi inserido no ultimo passo)
%   Exit (10) 5 is 2+3  creep				Sucesso!
%   Exit (9) sum([2, 3], 5)  creep			Retorna a fun��o com a lista ainda sendo chamada e o valor de 2+3 reservado no lugar da vari�vel
%   Call (9) _602 is 1+5  creep			_602 recebe 1(primeiro elemento da lista) + 5(Soma feita no ultimo passo)
%   Exit (9) 6 is 1+5  creep				Sucesso!
%   Exit (8) sum([1, 2, 3], 6)  creep			Retorna a lista original e o valor da soma de seus elementos
%	X = 6.						O resultado da soma de todos os elementos da lista � 6!
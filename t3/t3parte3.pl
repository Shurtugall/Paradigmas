%		PROVA OBI 2016

%	Fase 1: modalidade inicial

% Quest�o 1. Quantos palitos s�o necess�rios para
% construir o diagrama de n�mero 5?

% (A) 9
% (B) 11
% (C) 13
% (D) 15
% (E) 18

%-------------------RESOLU��O-------------------
% D � o diagrama
% P s�o os palitos

triangulos(D,P):-
	X is D*2 + 1,
	P = X.


% Sa�das testando todos os valores das quest�es:
% ?- triangulos(5,9).
% false.

% ?- triangulos(5,11).
% true.

% ?- triangulos(5,13).
% false.

% ?- triangulos(5,15).
% false.

% ?- triangulos(5,18).
% false. 

%------------------------------------------------



% OBS: o mesmo programa responde a quest�o 2.

% Quest�o 2.Quantos palitos s�o necess�rios para
% contruir o diagrama de n�mero 60?

% (A) 90
% (B) 111
% (C) 121
% (D) 163
% (E) 180

%-----------------RESOLU��O----------------------

% Basta passar uma vari�vel no lugar da quantidade de palitos

% ?- triangulos(60,X).
% X = 121.

%------------------------------------------------



% A quest�o 3 pode ser resolvida com alguns ajustes na nossa 
% fun��o b�sica. Fazemos o processo inverso

% Quest�o 3. Qual o n�mero do maior diagrama
% que � poss�vel construir com uma caixa de palitos
% de f�sforo que cont�m 42 palitos?

% (A) 14
% (B) 15
% (C) 18
% (D) 19
% (E) 20

%-----------------RESOLU��O-------------------

triangulosOP(D,P):-
	X is (P-1),
	Y is  X // 2,
	D = Y.

% Testando: passamos X(Valor do diagrama que queremos
% saber e 42 como a quantidade de palitos dispon�veis

% ?- triangulosOP(X,42).
% X = 20

%---------------------------------------------
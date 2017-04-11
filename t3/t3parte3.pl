%		PROVA OBI 2016

%	Fase 1: modalidade inicial

% Questão 1. Quantos palitos são necessários para
% construir o diagrama de número 5?

% (A) 9
% (B) 11
% (C) 13
% (D) 15
% (E) 18

%-------------------RESOLUÇÃO-------------------
% D é o diagrama
% P são os palitos

triangulos(D,P):-
	X is D*2 + 1,
	P = X.


% Saídas testando todos os valores das questões:
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



% OBS: o mesmo programa responde a questão 2.

% Questão 2.Quantos palitos são necessários para
% contruir o diagrama de número 60?

% (A) 90
% (B) 111
% (C) 121
% (D) 163
% (E) 180

%-----------------RESOLUÇÃO----------------------

% Basta passar uma variável no lugar da quantidade de palitos

% ?- triangulos(60,X).
% X = 121.

%------------------------------------------------



% A questão 3 pode ser resolvida com alguns ajustes na nossa 
% função básica. Fazemos o processo inverso

% Questão 3. Qual o número do maior diagrama
% que é possível construir com uma caixa de palitos
% de fósforo que contém 42 palitos?

% (A) 14
% (B) 15
% (C) 18
% (D) 19
% (E) 20

%-----------------RESOLUÇÃO-------------------

triangulosOP(D,P):-
	X is (P-1),
	Y is  X // 2,
	D = Y.

% Testando: passamos X(Valor do diagrama que queremos
% saber e 42 como a quantidade de palitos disponíveis

% ?- triangulosOP(X,42).
% X = 20

%---------------------------------------------
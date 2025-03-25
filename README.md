# 3D-Spinning-Cube-CPP
Um cubo 3D que gira em torno de um espaço 2D no terminal.


![Demonstração do projeto](cube.gif)

Esse codigo foi baseado no famoso codigo "Spinning Donut" https://www.a1k0n.net/2011/07/20/donut-math.html
O codigo utiliza matrizes de rotação para simular um efeito de rotação 3D em um espaço 2D, armazenando a multiplicação da matriz nos respectivos eixos [X Y Z].
Além disso, utiliza-se de tecnicas como z-Buffer (https://pt.wikipedia.org/wiki/Z-buffer) para emular a profundidade do campo, criando uma perspectiva falsa em relação a cada eixo
O codigo não só possibilita a representação geometrica de um cubo, mas também de qualquer outra forma se escrita corretamente.

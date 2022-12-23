
# Escultor 3d - part 3

**_Atualização:_**
Foi criado uma interface gráfica com o qt - c++ para o escultor digital 3d.

## como usar a interface?

A interface trabalha com alguns tipos de configurações, entre elas estão:
### 1. Definindo a cor de desenho:

No canto inferior direito da interface, encontra-se uma "caixa" de configurações ao qual podemos definir os valores do R (red), G (green) e B (blue) através de três slides horizontais.

### 2. Definindo o tipo do desenho:

No canto superior direito da interface, podemos selecionar atraves de radiosButtons qual o modo de desenho vai ser escolhido. Entre os modo temos: putVoxel (desenha um elemento de voxel), cutVoxel (apaga um elemento de Voxel), putBox (desenha uma caixa de Voxel com uma largura x, altura y e profundidade z definidas pelo usuário), cutBox (apaga uma caixa de Voxel com largura x, altura y e profundidade z definidas pelo usuário), PutSphere (desenha uma esfera de raio "r" definido pelo usuário), cutSphere (apaga uma esfera de raio "r" definido pelo usuário), putEllipsoid (desenha uma elipsoide com raio x, raio y e raio z definidos pelo usuário) e cutEllipsoid (apaga uma elipsoide com raio x, raio y e raio z definidos pelo usuário).

### 3. Definindo alguns parâmetros do desenho:

Alguns parâmetros podem ser definidos para o seu desenho na parte lateral direita da interface.

### 4. O desenho:

O desenho pode ser feito clicando na área de desenho definido pela grade de desenho. Abaixo da tela de desenho, você pode escolher em qual plano z voce deseja desenhar com a manipulação de um slider.

### 5. Salvamento do desenho e a geração de um arquivo em .off

O arquivo desenvolvido pelo usuário pode ser salvo através do botão salvar, encontrado na parte superior direita. O arquivo gerado se encontrará na pasta base do build com o nome "teste1.off".



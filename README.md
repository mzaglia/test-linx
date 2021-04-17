# test-linx
Backend Engineer test for Linx.

## Dependências
Antes de começar é necessário realizar a instalação das seguintes depêndencias: _CMake_, _Make_ , _g++_, _git_, _libreadline-dev_ e _libboost-dev_

Para isso execute o comando a seguir
```shell
sudo apt-get install --no-install-recommends -y g++ make cmake git libreadline-dev libboost-dev
```

## Clonando

Para iniciar é preciso realizar o clone deste projeto e navegar até o diretório criado

```
git clone https://github.com/mzaglia/test-linx
cd test-linx
```

## Build

Para realizar esta etapa é necessário inicializar os _submodules_ do _git_, isto irá realizar o clone dos repositórios utilizados como dependência.

```
git submodule update --init
```

Em seguida é necessário configurar o projeto através do _CMake_, para isto execute o seguinto comando:

```
cmake -DCMAKE_INSTALL_PREFIX="." -DCMAKE_BUILD_TYPE=Release -B build
```
Caso queira alterar o caminho de instalação é possível alterar o parametro `-DDCMAKE_INSTALL_PREFIX` para o caminho de sua preferência.

Após configurar o projeto é necessário realizar a compilação

```
 cmake --build . --target processador -- -j4
```
## Instalação

É possível instalar o programa através do seguinte comando
```
cmake --install build
```

## Executando

Após a instalação navegue até o diretório de instalacão e execute o comando
```
./processador
```

## Executando através do Docker
Caso queira é possível utilizar o programa através do docker.

Faça o build da imagem
```
docker build -t test-linx .
```

em seguida é possível executar

```
docker run -it test-linx
```

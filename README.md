# test-linx

[![Build Status](https://cloud.drone.io/api/badges/mzaglia/test-linx/status.svg)](https://cloud.drone.io/mzaglia/test-linx)
![Docker Build Status](https://img.shields.io/docker/build/mzaglia/test-linx)
![Docker Image Version (latest by date)](https://img.shields.io/docker/v/mzaglia/test-linx)


Este repositório contém o desafio da Linx para a vaga de Engenheiro de Backend.

## Sobre

Este programa realiza consultas em produtos e retorna os 20 resultados com melhor score.

Para isto foi utilizado o [_Inverted Index_](https://en.wikipedia.org/wiki/Inverted_index) e o coeficiente de similaridade [Sørensen–Dice](https://en.wikipedia.org/wiki/S%C3%B8rensen%E2%80%93Dice_coefficient) para ranquear os resultados.

O código foi compilado e executado no _Ubuntu 20.04_.

## Dependências
Antes de começar é necessário realizar a instalação das seguintes dependências: _CMake_, _Make_ , _g++_, _git_, _libreadline-dev_ e _libboost-dev_

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

Em seguida é necessário configurar o projeto através do _CMake_, para isto execute o seguinte comando

```
cmake -DCMAKE_INSTALL_PREFIX="." -DCMAKE_BUILD_TYPE=Release -B build
```
Caso queira alterar o caminho de instalação é possível alterar o parâmetro `-DCMAKE_INSTALL_PREFIX` para o caminho de sua preferência.

Após configurar o projeto é necessário realizar a compilação

```
make -C build && make -C build install
```

## Executando

Após a instalação execute o programa
```
./bin/processador
```

A seguir é possível ver um exemplo do programa em execução

```
Bem vindo ao processador de consultas! (Para sair digite /sair)
> Digite aqui sua consulta: carrinho de bebe
#1 - "5AAVITO2PTO" - "Carrinho de Bebê Avito Style Preto - ABC Design"
#2 - "5AAVITOAZL" - "Carrinho de Bebê Avito Jeans - ABC Design"
#3 - "5AAVITOCNZ" - "Carrinho de Bebê Avito Cinza - ABC Design"
#4 - "6GMARISPTO" - "Carrinho de Bebê Maris Preto - GB"
#5 - "6GMARISVRM" - "Carrinho de Bebê Maris Vermelho - GB"
#6 - "6GPOCKITPPTO" - "Carrinho de Bebê Pockit+ Preto - GB"
#7 - "6GPOCKITPVRM" - "Carrinho de Bebê Pockit+ Vermelho - GB"
#8 - "6GQBITPTO" - "Carrinho de Bebê Qbit+ Preto - GB"
#9 - "6GQBITVRM" - "Carrinho de Bebê Qbit+ Vermelho - GB"
#10 - "6KBB526CNZ" - "Carrinho de Bebê Agile Cinza - Multikids - BB526"
#11 - "6YBALIOSMPTO" - "Carrinho de Bebê Balios M Preto - Cybex"
#12 - "6YBALIOSMVRM" - "Carrinho de Bebê Balios M Vermelho - Cybex"
#13 - "6YCJPRIAMLSC00" - "Carrinho de Bebe Priam Trekking com Lux Seat Cinza - Cybex"
#14 - "6YCJPRIAMLSP00" - "Carrinho de Bebe Priam Trekking com Lux Seat Preto - Cybex"
#15 - "6YCJRAACCBE200" - "Carrinho de Bebe Mios Laranja - Cybex"
#16 - "6YCJRAACCBE201" - "Carrinho de Bebe Mios Preto  - Cybex"
#17 - "6YCJRAACCBE202" - "Carrinho de Bebe Mios Azul - Cybex"
#18 - "Y1IMP01362CNZ" - "Carrinho de Bebê Next Grey Denim - Safety 1st"
#19 - "Y1IMP91526AZL" - "Carrinho de Bebê Trend Azul - Safety 1st"
#20 - "YMIMP01374PTO" - "Carrinho de Bebê Dana For2 Preto - Maxi-Cosi"
Consulta concluída em: 3ms
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

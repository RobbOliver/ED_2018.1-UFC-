#include <lib/pen.h>

void trigo (Pen &p, int lado){
    if(lado < 1)
        return;

    p.setColor(232,181,85);

    int angulo = 40;

    for (int i = 0; i < 4; i++) {
        p.walk(lado);
        p.right(angulo);
        trigo(p,lado/3);
        p.left(2 * angulo);
        trigo(p,lado/3);
        p.right(angulo);
    }

    p.walk(-lado*4);

}

void fractal_trigo(Pen &p){
    p.setHeading(90);
    p.setXY(500,680);
    trigo(p,100);
}

void espiral(Pen &p, int tam, int rotacao){
    if(tam > 150){
        return;
    }
    quadrado(p,tam,4);
    p.up();
    rotacao += 30;
    p.left(rotacao);
    p.walk(tam * 2);
    p.setHeading(0);
    tam += 5;
    p.down();
    espiral(p,tam,rotacao);

}

void fractal_espiral(Pen &p){
    espiral(p,5,30);
}


void rotacao(Pen &p, int tam){
    if(tam < 5){
        return;
    }
    p.walk(tam);
    tam -= 5;
    p.right(90);
    p.setColor(rand()%255, rand()%255, rand()%255);
    rotacao(p,tam);

}

void quadrado(Pen &p, int tam, int l){
    if(l < 1){
        return;
    }
    p.walk(tam);
    l--;
    p.left(90);
    p.setColor(rand()%255, rand()%255, rand()%255);
    quadrado(p,tam,l);

}

    void triangulo(Pen &p, int lado){
    if(lado < 10)
        return;
    for(int i = 0; i < 3; i++){
        p.setColor(rand() % 255, rand() % 255, rand() % 255);
        //p.setThickness(rand() % 3); Não sei retirar o 0 ainda.
        p.walk(lado);
        p.left(120);
        triangulo(p, lado/2);
    }
}

    void embuarvore(Pen& p, int lado){
    float ang = 35;
    float dec = 0.75;
    lado -= (p.rand() % 9 - 3);
    if(lado < 10)
        return;
    p.setColor(rand() % 255, rand() % 255, rand() % 255);
    p.walk(lado);
    p.right(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.left(ang);
    embuarvore(p, lado * dec);
    p.right(ang);
    //p.setColor(sf::Color::Red);
    p.walk(-lado);
}

void fractal(){
    //tamanho do painel
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 400 y 500
    p.setXY(400, 500);

    //faz o pincel apontar pra direita
    //está em graus!
    p.setHeading(0);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(0);

    //embuarvore(p, 100);
    //triangulo(p, 400);
    //    fractal_rotacao(p);
    //    fractal_espiral(p);
    //    triangulo(p);
    //    fractal_girasol(p);
    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}

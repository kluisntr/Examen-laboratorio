#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include<SDL2/SDL_mixer.h>
#include <iostream>

using namespace std;
int ciclo=0;
int ciclo2=0;
int posx1=1;
int posy1=1;

int vida1=70,vida2=50,vida3=20,vida4=70,vida5=50,vida6=20;
int ataque1=15,ataque2=5,ataque3=2,ataque4=15,ataque5=5,ataque6=2;
int  posicion()
{
    return 0;
};

bool turno(bool estado)
{
if(estado=true)
{
estado=false;
return estado;
}
if(estado=false)
{
estado=true;
return estado;
}
};
bool juga=true;


SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
int tile_white=32;
Mix_Music *musica = NULL,*movimiento = NULL,*muerte = NULL,*cursor = NULL,*ganador = NULL;
int posx=0;
int posy=0;
int main()
{
     //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Battle Pamper Cayu", 100, 100, 1376/*WIDTH*/, 768/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //sdlmixer
     if(Mix_OpenAudio(22050, AUDIO_S16, 2, 4096))
    {
        return 40;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    musica = Mix_LoadMUS("sonidofondo.ogg");
    Mix_PlayMusic(musica, 1);

    muerte = Mix_LoadMUS("muerte.ogg");
    cursor = Mix_LoadMUS("cursor.ogg");
    movimiento = Mix_LoadMUS("mover.ogg");
    ganador = Mix_LoadMUS("sonidofondo.ogg");


    SDL_Texture* texture_piso,* texture_vida1,*texture_vida2,*texture_pared,*texture_heroebueno,
    *texture_heroemalo,*texture_magobueno,*texture_magomalo,*texture_espadabuena,
    *texture_espadamalo,*texture_Cursor1,*texture_Cursor11,*texture_Cursor,*texture_Seleccionado,
    *texture_menu,*texture_jugador1,*texture_jugador2,*texture_winer1,*texture_winer2;

     SDL_Rect Rectangulojugador;
    SDL_Rect Rectanguloopcion;
    SDL_Rect Rectanguloheroebueno;
    SDL_Rect Rectangulopiso;
    SDL_Rect Rectangulomuro;
     SDL_Rect Rectanguloheroemalo;
     SDL_Rect Rectangulomagomalo;
     SDL_Rect Rectangulomagobueno;
     SDL_Rect Rectanguloespadabuena;
     SDL_Rect Rectanguloespadamalo;
     SDL_Rect Rectangulovida;
     SDL_Rect Rectanguloseleccionado;


    SDL_Rect Rectangulocursor;

     texture_winer1= IMG_LoadTexture(renderer,"winer1.png");
     texture_winer2= IMG_LoadTexture(renderer,"winer2.png");

     texture_jugador1= IMG_LoadTexture(renderer,"JUGADOR1.png");
     texture_jugador2= IMG_LoadTexture(renderer,"JUGADOR2.png");

    texture_menu= IMG_LoadTexture(renderer,"opciones.png");
    texture_piso= IMG_LoadTexture(renderer,"piso.png");
    texture_pared= IMG_LoadTexture(renderer,"muro.png");

    texture_heroemalo= IMG_LoadTexture(renderer,"heroemalo.png");
    texture_heroebueno= IMG_LoadTexture(renderer,"heroebueno.png");

    texture_espadabuena= IMG_LoadTexture(renderer,"espadabueno.png");
    texture_espadamalo= IMG_LoadTexture(renderer,"espadamalo.png");

    texture_vida1= IMG_LoadTexture(renderer,"vida2.png");
    texture_vida2= IMG_LoadTexture(renderer,"vida3.png");
        texture_Cursor1= IMG_LoadTexture(renderer,"cursorbueno.png");
        texture_Cursor11= IMG_LoadTexture(renderer,"cursorbueno2.png");
        texture_Cursor= IMG_LoadTexture(renderer,"cursormalo.png");


      texture_magobueno= IMG_LoadTexture(renderer,"magobueno.png");
      texture_magomalo= IMG_LoadTexture(renderer,"magomalo.png");


    texture_Seleccionado= IMG_LoadTexture(renderer,"seleccion.png");

      Rectangulojugador.x=0;
     Rectangulojugador.y=17*tile_white;
     Rectangulojugador.h=4*tile_white;
      Rectangulojugador.w=19*tile_white ;


     Rectanguloopcion.x=39*tile_white;
     Rectanguloopcion.y=0;
     Rectanguloopcion.h=17*tile_white;
      Rectanguloopcion.w=128 ;
//rectangulos de vida-------------------------------------------------------------

    Rectangulovida.x=32;
    Rectangulovida.y=32;
    Rectangulovida.w=tile_white;
    Rectangulovida.h=tile_white;
//rectangulos de los heroes -------------------------------------------------------
    Rectanguloheroebueno.x=32;
    Rectanguloheroebueno.y=32;
    Rectanguloheroebueno.w=tile_white;
    Rectanguloheroebueno.h=tile_white;

    Rectanguloheroemalo.x=32;
    Rectanguloheroemalo.y=32;
    Rectanguloheroemalo.w=tile_white;
    Rectanguloheroemalo.h=tile_white;
//rectangulo delos espadachines  --------------------------------------------------
    Rectanguloespadabuena.x=32;
    Rectanguloespadabuena.y=32;
    Rectanguloespadabuena.w=tile_white;
    Rectanguloespadabuena.h=tile_white;

    Rectanguloespadamalo.x=32;
    Rectanguloespadamalo.y=32;
    Rectanguloespadamalo.w=tile_white;
    Rectanguloespadamalo.h=tile_white;
//rectangulos de los magos       --------------------------------------------------
    Rectangulomagobueno.x=32;
    Rectangulomagobueno.y=32;
    Rectangulomagobueno.w=tile_white;
    Rectangulomagobueno.h=tile_white;

    Rectangulomagomalo.x=32;
    Rectangulomagomalo.y=32;
    Rectangulomagomalo.w=tile_white;
    Rectangulomagomalo.h=tile_white;


    Rectangulomuro.x=0;
    Rectangulomuro.y=0;
    Rectangulomuro.w=tile_white;
    Rectangulomuro.h=tile_white;

    Rectangulopiso.x=0;
    Rectangulopiso.y=0;
    Rectangulopiso.w=tile_white;
    Rectangulopiso.h=tile_white;
//cursor --------------------------------------------
    Rectangulocursor.x=tile_white;
    Rectangulocursor.y=0;
    Rectangulocursor.w=tile_white;
    Rectangulocursor.h=tile_white;

      Rectanguloseleccionado.x=0;
    Rectanguloseleccionado.y=0;
    Rectanguloseleccionado.w=tile_white;
    Rectanguloseleccionado.h=tile_white;

 int frame=0;
 int frame_actual=0;
 int frame_anterior=0;
 int cursor_x=1;
 int cursor_y=1;
 bool seleccion=false,seleccion1=false,seleccion2=false,seleccion3=false,seleccion4=false,seleccion5=false;





    int arr[17][39]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,0,0,1},
                    {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
//movimientos de personajes y posicion de las cosas
                    int pss[17][39]=
                    {
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,11,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1},
                    {1,0,0,0,0,0,0,0,0,8,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,11,11,0,0,11,0,0,0,11,0,0,0,0,0,0,0,11,0,0,0,0,0,0,11,0,0,0,11,11,0,11,0,0,0,0,1},
                    {1,4,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,11,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11},
                    {1,11,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,11,0,0,11,0,0,0,0,0,0,11,1},
                    {1,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,11,0,0,0,0,0,8,0,0,0,0,11,0,0,0,0,0,7,11,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,11,11,1},
                    {1,0,0,0,0,0,0,0,0,0,11,0,0,11,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
                    };
                    int menus[22][39]={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,1,0,1,0,0,0,0,1},
                    {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,1,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1},
                    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1},
                    {1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};




//ciclo de movimiento


    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
        if(Event.type==SDL_QUIT)
            {
                return 0;

            }
            if(Event.type==SDL_KEYDOWN)

            {
            if(Event.key.keysym.sym==SDLK_w)
            {


                if(pss[cursor_y-1][cursor_x]!=1)
                {
                cursor_y--;


                Mix_PlayMusic(cursor, 2);
                Mix_PlayMusic(musica, 1);

                }


            }
            if(Event.key.keysym.sym==SDLK_s)
            {


                if(pss[cursor_y+1][cursor_x]!=1)

                {
                 Mix_PlayMusic(cursor, 2);
                 Mix_PlayMusic(musica, 1);
                  cursor_y++;
                }



            }

            if(Event.key.keysym.sym==SDLK_a)
            {

                if(pss[cursor_y][cursor_x-1]!=1)
                {
                 cursor_x--;
                  Mix_PlayMusic(cursor, 2);
                  Mix_PlayMusic(musica, 1);
                }

            }

            if(Event.key.keysym.sym==SDLK_d)
            {

                if(pss[cursor_y][cursor_x+1]!=1)
                {
                  cursor_x++;
                 Mix_PlayMusic(cursor, 2);
                 Mix_PlayMusic(musica, 1);
                }

            }
            if(Event.key.keysym.sym==SDLK_z)
            {

                   if(Rectanguloheroebueno.x==Rectangulocursor.x&&Rectanguloheroebueno.y==Rectangulocursor.y&&juga==true)
                   {

                   posx=cursor_x;
                   posy=cursor_y;

                   posx1=-4;
                  while(posx1<5){
                   posy1=-4;

                while(posy1<5){
                if(pss[posy+posy1][posx+posx1]==0)
                {

                    pss[posy+posy1][posx+posx1]=21;
                    posy1++;
                    cout<<"21"<<endl;
                    cout.flush();
                    }
                    else
                    {
                    cout<<"salto"<<endl;
                    cout.flush();
                       posy1++;

                    }

                        }
                        posx1++;
                        }

                    seleccion =true;
                    seleccion1=false;
                    seleccion2=false;
                     seleccion3=false;
                      seleccion4=false;
                      seleccion5=false;

                   }
                   if(Rectangulomagobueno.x==Rectangulocursor.x&&Rectangulomagobueno.y==Rectangulocursor.y&&juga==true){
                   posx=cursor_x;
                   posy=cursor_y;

                   posx1=-1;
                  while(posx1<2){
                   posy1=-1;

                while(posy1<2){
                if(pss[posy+posy1][posx+posx1]==0)
                {

                    pss[posy+posy1][posx+posx1]=21;
                    posy1++;
                    cout<<"21"<<endl;
                    cout.flush();
                    }
                    else
                    {
                    cout<<"salto"<<endl;
                    cout.flush();
                       posy1++;

                    }

                        }
                        posx1++;
                        }


                   seleccion =false;
                    seleccion1=true;
                    seleccion2=false;
                     seleccion3=false;
                      seleccion4=false;
                      seleccion5=false;
                   }
                   if(Rectanguloespadabuena.x==Rectangulocursor.x&&Rectanguloespadabuena.y==Rectangulocursor.y&&juga==true){
                   posx=cursor_x;
                   posy=cursor_y;
                    posx1=-3;
                  while(posx1<4){
                   posy1=-3;

                while(posy1<4){
                if(pss[posy+posy1][posx+posx1]==0)
                {

                    pss[posy+posy1][posx+posx1]=21;
                    posy1++;
                    cout<<"21"<<endl;
                    cout.flush();
                    }
                    else
                    {
                    cout<<"salto"<<endl;
                    cout.flush();
                       posy1++;

                    }

                        }
                        posx1++;
                        }
                   seleccion =false;
                    seleccion1=false;
                    seleccion2=true;
                     seleccion3=false;
                      seleccion4=false;
                      seleccion5=false;
                   }

                   //-----------------------------------------------------

                   if(Rectanguloheroemalo.x==Rectangulocursor.x&&Rectanguloheroemalo.y==Rectangulocursor.y&&juga==false){

                   posx=cursor_x;
                   posy=cursor_y;
                     posx1=-4;
                  while(posx1<5){
                   posy1=-4;

                while(posy1<5){
                if(pss[posy+posy1][posx+posx1]==0)
                {

                    pss[posy+posy1][posx+posx1]=21;
                    posy1++;
                    cout<<"21"<<endl;
                    cout.flush();
                    }
                    else
                    {
                    cout<<"salto"<<endl;
                    cout.flush();
                       posy1++;

                    }

                        }
                        posx1++;
                        }
                   seleccion =false;
                    seleccion1=false;
                    seleccion2=false;
                     seleccion3=true;
                      seleccion4=false;
                      seleccion5=false;
                   }
                   if(Rectanguloespadamalo.x==Rectangulocursor.x&&Rectanguloespadamalo.y==Rectangulocursor.y&&juga==false){
                   posx=cursor_x;
                   posy=cursor_y;
                    posx1=-3;
                  while(posx1<4){
                   posy1=-3;

                while(posy1<4){
                if(pss[posy+posy1][posx+posx1]==0)
                {

                    pss[posy+posy1][posx+posx1]=21;
                    posy1++;
                    cout<<"21"<<endl;
                    cout.flush();
                    }
                    else
                    {
                    cout<<"salto"<<endl;
                    cout.flush();
                       posy1++;

                    }

                        }
                        posx1++;
                        }
                    seleccion =false;
                    seleccion1=false;
                    seleccion2=false;
                     seleccion3=false;
                      seleccion4=true;
                      seleccion5=false;
                   }
                   if(Rectangulomagomalo.x==Rectangulocursor.x&&Rectangulomagomalo.y==Rectangulocursor.y&&juga==false){
                   posx=cursor_x;
                   posy=cursor_y;
 posx1=-1;
                  while(posx1<2){
                   posy1=-1;

                while(posy1<2){
                if(pss[posy+posy1][posx+posx1]==0)
                {

                    pss[posy+posy1][posx+posx1]=21;
                    posy1++;
                    cout<<"21"<<endl;
                    cout.flush();
                    }
                    else
                    {
                    cout<<"salto"<<endl;
                    cout.flush();
                       posy1++;

                    }

                        }
                        posx1++;
                        }
                   seleccion =false;
                    seleccion1=false;
                    seleccion2=false;
                     seleccion3=false;
                      seleccion4=false;
                      seleccion5=true; }



            }




             if(Event.key.keysym.sym==SDLK_x)
            {

                   if(Rectanguloheroebueno.x==Rectangulocursor.x&&Rectanguloheroebueno.y==Rectangulocursor.y&&juga==true)
                   {
                   posx1=-4;
                  while(posx1<5){
                   posy1=-4;
                    while(posy1<5)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                   posx=0;
                   posy=0;

                    seleccion =false;
                   }
                    if(Rectangulomagobueno.x==Rectangulocursor.x&&Rectangulomagobueno.y==Rectangulocursor.y&&juga==true)
                    {
                    posx1=-1;
                  while(posx1<2){
                   posy1=-1;
                    while(posy1<2)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                   posx=0;
                   posy=0;
                    seleccion1 =false;
                   }
                   if(Rectanguloespadabuena.x==Rectangulocursor.x&&Rectanguloespadabuena.y==Rectangulocursor.y&&juga==true)
                    {
                    posx1=-3;
                  while(posx1<4){
                   posy1=-3;
                    while(posy1<4)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                   posx=0;
                   posy=0;
                    seleccion2 =false;
                   }



                   if(Rectanguloheroemalo.x==Rectangulocursor.x&&Rectanguloheroemalo.y==Rectangulocursor.y&&juga==false){
                    posx1=-4;
                  while(posx1<5){
                   posy1=-4;
                    while(posy1<5)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                    posx=0;
                   posy=0;
                   seleccion3 =false;
                   }
                   if(Rectanguloespadamalo.x==Rectangulocursor.x&&Rectanguloespadamalo.y==Rectangulocursor.y&&juga==false){
                   posx1=-3;
                  while(posx1<4){
                   posy1=-3;
                    while(posy1<4)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                   posx=0;
                   posy=0;
                   seleccion4 =false;
                   }
                   if(Rectangulomagomalo.x==Rectangulocursor.x&&Rectangulomagomalo.y==Rectangulocursor.y&&juga==false){
                   posx1=-1;
                  while(posx1<2){
                   posy1=-1;
                    while(posy1<2)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                   posx=0;
                   posy=0;
                   seleccion5 =false;
                   }


            }

            }
        }



        for(int x=0;x<39;x++)
        {
            for(int y=0;y<17;y++)
            {
            if(arr[y][x]==1)
            {
            Rectangulomuro.x=x*tile_white;
            Rectangulomuro.y=y*tile_white;
            SDL_RenderCopy(renderer, texture_pared, NULL, &Rectangulomuro);
            }
            else
            {
            Rectangulopiso.x=x*tile_white;
            Rectangulopiso.y=y*tile_white;
            SDL_RenderCopy(renderer, texture_piso, NULL, &Rectangulopiso);
            }

            if(pss[y][x]==2&&vida1>0)
            {
            Rectanguloheroebueno.x=x*tile_white;
            Rectanguloheroebueno.y=y*tile_white;
            SDL_RenderCopy(renderer, texture_heroebueno, NULL, &Rectanguloheroebueno);
            }
             if(pss[y][x]==3&&vida3>0)
            {
            Rectangulomagobueno.x=x*tile_white;
            Rectangulomagobueno.y=y*tile_white;
            SDL_RenderCopy(renderer, texture_magobueno, NULL, &Rectangulomagobueno);
            }
             if(pss[y][x]==4&&vida2>0)
            {

            Rectanguloespadabuena.x=x*tile_white;
            Rectanguloespadabuena.y=y*tile_white;
             SDL_RenderCopy(renderer, texture_espadabuena, NULL, &Rectanguloespadabuena);

            }
            if(pss[y][x]==5&&vida4>0)
            {
            Rectanguloheroemalo.x=x*tile_white;
            Rectanguloheroemalo.y=y*tile_white;
             SDL_RenderCopy(renderer, texture_heroemalo, NULL, &Rectanguloheroemalo);

            }
            if(pss[y][x]==6&&vida5>0)
            {
            Rectanguloespadamalo.x=x*tile_white;
            Rectanguloespadamalo.y=y*tile_white;
             SDL_RenderCopy(renderer, texture_espadamalo, NULL, &Rectanguloespadamalo);

            }
            if(pss[y][x]==7&&vida6>0)
            {
            Rectangulomagomalo.x=x*tile_white;
            Rectangulomagomalo.y=y*tile_white;
             SDL_RenderCopy(renderer, texture_magomalo, NULL, &Rectangulomagomalo);

            }

            if(pss[y][x]==8)
            {
            Rectangulovida.x=x*tile_white;
            Rectangulovida.y=y*tile_white;


            if(ciclo%2==0)
            {
            SDL_RenderCopy(renderer, texture_vida1, NULL, &Rectangulovida);
            }
            else
            {
             SDL_RenderCopy(renderer, texture_vida2, NULL, &Rectangulovida);
            }
             }


//////////seleccccionnnnnnnn

            if(pss[y][x]==21)
            {
            SDL_RenderCopy(renderer, texture_Seleccionado, NULL, &Rectangulopiso);
            }
            }
        }



if(Event.key.keysym.sym==SDLK_m )
            {
            //validacion de muerte de personajes

                    if(seleccion==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==true)
                    {
                    cout<<"heroe bueno"<<endl;
                    cout.flush();

                    Rectanguloheroebueno.x=Rectangulocursor.x;
                    Rectanguloheroebueno.y=Rectangulocursor.y;
                    pss[posy][posx]=0;

                     posx1=-4;
                  while(posx1<5){
                   posy1=-4;
                    while(posy1<5)
                    {
                    if(pss[posy+posy1][posx+posx1]==5)
                    {
                    cout<<vida4<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida4=vida4-ataque1;
                    Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida4<<endl;
                    cout.flush();
                    }
                    if(vida4<=0)
                    {
                    cout<<"murio heroe malo"<<endl;
                    cout.flush();
                    }

                    //muerte del de la espada

                    if(pss[posy+posy1][posx+posx1]==6)
                    {
                    cout<<vida5<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida5=vida5-ataque1;
                   Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida5<<endl;
                    cout.flush();
                    }
                    if(vida5<=0)
                    {
                    cout<<"murio espada malo"<<endl;
                    cout.flush();
                    }

                    //muerte para mago

                    if(pss[posy+posy1][posx+posx1]==5)
                    {
                    cout<<vida6<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida6=vida6-ataque1;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida6<<endl;
                    cout.flush();
                    }
                    if(vida6<=0)
                    {
                    cout<<"murio mago malo"<<endl;
                    cout.flush();
                    }


                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }

                    pss[cursor_y][cursor_x]=2;

                    seleccion=false;

                    juga=false;
                    }

                   if(seleccion1==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==true)
                    {
                    cout<<"mago bueno"<<endl;
                    cout.flush();

                    Rectangulomagobueno.x=Rectangulocursor.x;
                    Rectangulomagobueno.y=Rectangulocursor.y;
                    pss[posy][posx]=0;

                        posx1=-1;
                  while(posx1<2){
                   posy1=-1;
                    while(posy1<2)
                    {
                    if(pss[posy+posy1][posx+posx1]==5)
                    {
                    cout<<vida4<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida4=vida4-ataque3;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida4<<endl;
                    cout.flush();
                    }
                    if(vida4<=0)
                    {
                    cout<<"murio heroe malo"<<endl;
                    cout.flush();
                    }

                    //muerte del de la espada

                    if(pss[posy+posy1][posx+posx1]==6)
                    {
                    cout<<vida5<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida5=vida5-ataque3;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida5<<endl;
                    cout.flush();
                    }
                    if(vida5<=0)
                    {
                    cout<<"murio espada malo"<<endl;
                    cout.flush();
                    }

                    //muerte para mago

                    if(pss[posy+posy1][posx+posx1]==7)
                    {
                    cout<<vida6<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida6=vida6-ataque3;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida6<<endl;
                    cout.flush();
                    }
                    if(vida6<=0)
                    {
                    cout<<"murio mago malo"<<endl;
                    cout.flush();
                    }


                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }

                    pss[cursor_y][cursor_x]=3;
                    juga=false;
                    seleccion1=false;
                    }
                    if(seleccion2==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==true)
                    {
                    cout<<"espadachin bueno"<<endl;
                    cout.flush();

                    Rectanguloespadabuena.x=Rectangulocursor.x;
                    Rectanguloespadabuena.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                        posx1=-3;
                  while(posx1<4){
                   posy1=-3;
                    while(posy1<4)
                    {
                    if(pss[posy+posy1][posx+posx1]==5)
                    {
                    cout<<vida4<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida4=vida4-ataque2;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida4<<endl;
                    cout.flush();
                    }
                    if(vida4<=0)
                    {
                    cout<<"murio heroe malo"<<endl;
                    cout.flush();
                    }

                    //muerte del de la espada

                    if(pss[posy+posy1][posx+posx1]==6)
                    {
                    cout<<vida5<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida5=vida5-ataque2;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida5<<endl;
                    cout.flush();
                    }
                    if(vida5<=0)
                    {
                    cout<<"murio espada malo"<<endl;
                    cout.flush();
                    }

                    //muerte para mago

                    if(pss[posy+posy1][posx+posx1]==7)
                    {
                    cout<<vida6<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida6=vida6-ataque2;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida6<<endl;
                    cout.flush();
                    }
                    if(vida6<=0)
                    {
                    cout<<"murio mago malo"<<endl;
                    cout.flush();
                    }


                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }

                    pss[cursor_y][cursor_x]=4;
                    juga=false;
                    seleccion2=false;
                    }

                    //----------------------------------comienso de los personajes malos--------------------------
                    if(seleccion3==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==false)
                    {
                    cout<<"heroe malo"<<endl;
                    cout.flush();

                    Rectanguloheroemalo.x=Rectangulocursor.x;
                    Rectanguloespadabuena.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                           posx1=-4;
                  while(posx1<5){
                   posy1=-4;
                    while(posy1<5)
                    {
                    if(pss[posy+posy1][posx+posx1]==2)
                    {
                    cout<<vida1<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida1=vida1-ataque4;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida1<<endl;
                    cout.flush();
                    }
                    if(vida1<=0)
                    {
                    cout<<"murio heroe bueno"<<endl;
                    cout.flush();
                    }

                    //muerte del de la espada

                    if(pss[posy+posy1][posx+posx1]==3)
                    {
                    cout<<vida2<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida2=vida2-ataque4;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida2<<endl;
                    cout.flush();
                    }
                    if(vida2<=0)
                    {
                    cout<<"murio espada bueno"<<endl;
                    cout.flush();
                    }

                    //muerte para mago

                    if(pss[posy+posy1][posx+posx1]==4)
                    {
                    cout<<vida3<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida3=vida3-ataque4;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida3<<endl;
                    cout.flush();
                    }
                    if(vida3<=0)
                    {
                    cout<<"murio mago bueno"<<endl;
                    cout.flush();
                    }


                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }

                    pss[cursor_y][cursor_x]=5;
                    juga=true;
                    seleccion3=false;
                    }
                    if(seleccion4==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==false)
                    {
                    cout<<"espadachin malo"<<endl;
                    cout.flush();

                    Rectanguloespadamalo.x=Rectangulocursor.x;
                    Rectanguloespadamalo.y=Rectangulocursor.y;
                    pss[posy][posx]=0;

                         posx1=-3;
                  while(posx1<4){
                   posy1=-3;
                    while(posy1<4)
                    {
                    if(pss[posy+posy1][posx+posx1]==2)
                    {
                    cout<<vida1<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida1=vida1-ataque5;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida1<<endl;
                    cout.flush();
                    }
                    if(vida1<=0)
                    {
                    cout<<"murio heroe bueno"<<endl;
                    cout.flush();
                    }

                    //muerte del de la espada

                    if(pss[posy+posy1][posx+posx1]==3)
                    {
                    cout<<vida2<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida2=vida2-ataque5;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida2<<endl;
                    cout.flush();
                    }
                    if(vida2<=0)
                    {
                    cout<<"murio espada bueno"<<endl;
                    cout.flush();
                    }

                    //muerte para mago

                    if(pss[posy+posy1][posx+posx1]==4)
                    {
                    cout<<vida3<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida3=vida3-ataque5;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida3<<endl;
                    cout.flush();
                    }
                    if(vida3<=0)
                    {
                    cout<<"murio mago bueno"<<endl;
                    cout.flush();
                    }


                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }



                    pss[cursor_y][cursor_x]=6;
                    juga=true;
                    seleccion4=false;
                    }
                    if(seleccion5==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==false)
                    {
                    cout<<"mago malo"<<endl;
                    cout.flush();

                    Rectangulomagomalo.x=Rectangulocursor.x;
                    Rectangulomagomalo.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                         posx1=-1;
                  while(posx1<2){
                   posy1=-1;
                    while(posy1<2)
                    {
                    if(pss[posy+posy1][posx+posx1]==2)
                    {
                    cout<<vida1<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida1=vida1-ataque6;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida1<<endl;
                    cout.flush();
                    }
                    if(vida1<=0)
                    {
                    cout<<"murio heroe bueno"<<endl;
                    cout.flush();
                    }

                    //muerte del de la espada

                    if(pss[posy+posy1][posx+posx1]==3)
                    {
                    cout<<vida2<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida2=vida2-ataque6;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida2<<endl;
                    cout.flush();
                    }
                    if(vida2<=0)
                    {
                    cout<<"murio espada bueno"<<endl;
                    cout.flush();
                    }

                    //muerte para mago

                    if(pss[posy+posy1][posx+posx1]==4)
                    {
                    cout<<vida3<<endl;
                     cout<<"--------------------------------------"<<endl;
                    vida3=vida3-ataque6;
                     Mix_PlayMusic(muerte, 1);
                     Mix_PlayMusic(musica, 1);
                    cout<<vida3<<endl;
                    cout.flush();
                    }
                    if(vida3<=0)
                    {
                    cout<<"murio mago bueno"<<endl;
                    cout.flush();
                    }


                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }


                    pss[cursor_y][cursor_x]=7;
                    juga=true;
                    seleccion5=false;
                    }
            }

/////////////////////////fin del ataque

        if(Event.key.keysym.sym==SDLK_SPACE)
            {
            //validacion de movimiento

                    if(seleccion==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==true)
                    {
                    cout<<"heroe bueno"<<endl;
                    cout.flush();

                    Rectanguloheroebueno.x=Rectangulocursor.x;
                    Rectanguloheroebueno.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                     posx1=-4;
                  while(posx1<5){
                   posy1=-4;
                    while(posy1<5)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }

                    pss[cursor_y][cursor_x]=2;

                    seleccion=false;

                    juga=false;
                    }

                   if(seleccion1==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==true)
                    {
                    cout<<"mago bueno"<<endl;
                    cout.flush();
                    posx1=-2;
                  while(posx1<2){
                   posy1=-2;
                    while(posy1<2)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }

                    Rectangulomagobueno.x=Rectangulocursor.x;
                    Rectangulomagobueno.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                    pss[cursor_y][cursor_x]=3;
                    juga=false;
                    seleccion1=false;
                    }
                    if(seleccion2==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==true)
                    {
                    cout<<"espadachin bueno"<<endl;
                    cout.flush();
                    posx1=-3;
                  while(posx1<4){
                   posy1=-3;
                    while(posy1<4)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                    Rectanguloespadabuena.x=Rectangulocursor.x;
                    Rectanguloespadabuena.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                    pss[cursor_y][cursor_x]=4;
                    juga=false;
                    seleccion2=false;
                    }

                    //-------------------------------------------------------------------------------
                    if(seleccion3==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==false)
                    {
                    cout<<"heroe malo"<<endl;
                    cout.flush();
                    posx1=-4;
                  while(posx1<5){
                   posy1=-4;
                    while(posy1<5)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                    Rectanguloheroemalo.x=Rectangulocursor.x;
                    Rectanguloespadabuena.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                    pss[cursor_y][cursor_x]=5;
                    juga=true;
                    seleccion3=false;
                    }
                    if(seleccion4==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==false)
                    {
                    cout<<"espadachin malo"<<endl;
                    cout.flush();
                    posx1=-3;
                  while(posx1<4){
                   posy1=-3;
                    while(posy1<4)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                    Rectanguloespadamalo.x=Rectangulocursor.x;
                    Rectanguloespadamalo.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                    pss[cursor_y][cursor_x]=6;
                    juga=true;
                    seleccion4=false;
                    }
                    if(seleccion5==true&&pss[cursor_y][cursor_x]==21&&pss[cursor_y][cursor_x]!=11&&juga==false)
                    {
                    cout<<"mago malo"<<endl;
                    cout.flush();
                    posx1=-1;
                  while(posx1<2){
                   posy1=-1;
                    while(posy1<2)
                    {
                    if(pss[posy+posy1][posx+posx1]==21)
                    {
                    pss[posy+posy1][posx+posx1]=0;
                    posy1++;
                    cout<<"0"<<endl;
                    cout.flush();
                    }else
                    {
                    posy1++;
                    cout<<"salto"<<endl;
                    cout.flush();
                    }

                    }
                    posx1++;
                    }
                    Rectangulomagomalo.x=Rectangulocursor.x;
                    Rectangulomagomalo.y=Rectangulocursor.y;
                    pss[posy][posx]=0;
                    pss[cursor_y][cursor_x]=7;
                    juga=true;
                    seleccion5=false;
                    }
            }
            //personajes buenos




        Rectangulocursor.x=cursor_x*tile_white;
        Rectangulocursor.y=cursor_y*tile_white;

        if(juga==true)
        {
       SDL_RenderCopy(renderer, texture_Cursor1, NULL, &Rectangulocursor);
       SDL_RenderCopy(renderer, texture_jugador1, NULL, &Rectangulojugador);
        }
        else
        {
       SDL_RenderCopy(renderer, texture_Cursor, NULL, &Rectangulocursor);
       SDL_RenderCopy(renderer, texture_jugador2, NULL, &Rectangulojugador);
        }



            if(seleccion==true)
            {
            SDL_RenderCopy(renderer,texture_Seleccionado,NULL,&Rectanguloheroebueno );
            }
            if(seleccion1==true)
            {
            SDL_RenderCopy(renderer,texture_Seleccionado,NULL,&Rectangulomagobueno );
            }
            if(seleccion2==true)
            {
            SDL_RenderCopy(renderer,texture_Seleccionado,NULL,&Rectanguloespadabuena );
            }
            if(seleccion3==true)
            {
            SDL_RenderCopy(renderer,texture_Seleccionado,NULL,&Rectanguloheroemalo );
            }
            if(seleccion4==true)
            {
            SDL_RenderCopy(renderer,texture_Seleccionado,NULL,&Rectanguloespadamalo );
            }
            if(seleccion5==true)
            {
            SDL_RenderCopy(renderer,texture_Seleccionado,NULL,&Rectangulomagomalo );
            }



                 SDL_RenderCopy(renderer,texture_menu,NULL,&Rectanguloopcion );


                 if(vida1<=0&&vida2<=0&&vida3<=0)
                 {
                 Rectangulojugador.x=7*tile_white;
                 Rectangulojugador.y=3*tile_white;
                  SDL_RenderCopy(renderer,texture_winer2,NULL,&Rectangulojugador );
                 }
                 if(vida4<=0&&vida5<=0&&vida6<=0)
                 {
                 Rectangulojugador.x=7*tile_white;
                 Rectangulojugador.y=3*tile_white;
                  SDL_RenderCopy(renderer,texture_winer1,NULL,&Rectangulojugador );
                 }

                        SDL_RenderPresent(renderer);

if(frame%50==0)
{
ciclo++;

}

if(frame%25==0)
{
ciclo2++;

}




        frame++;
        int frame_actual=SDL_GetTicks()-frame_anterior;
        frame_anterior=SDL_GetTicks();
        if(17-frame_actual>0)
        SDL_Delay(17-frame_actual);

    }


    return 0;
}

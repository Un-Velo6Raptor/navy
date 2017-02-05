/*
** set_pixel_color.c for  in /home/januar_m/delivery/PSU/PSU_2016_navy/bonus
** 
** Made by Martin Januario
** Login   <martin.januario@epitech.eu>
** 
** Started on  Wed Feb  1 21:07:13 2017 
** Last update Wed Feb  1 21:07:15 2017 
*/

#include	<SFML/Graphics/RenderWindow.h>
#include	<SFML/Graphics/Texture.h>
#include	<SFML/Graphics/Sprite.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"framefuffer.h"
#include	"my.h"

sfColor		set_pixel_color(int a, int b, int c)
{
  sfColor	pixels_color;

  pixels_color.r = a;
  pixels_color.g = b;
  pixels_color.b = c;
  pixels_color.a = 255;
  return (pixels_color);
}


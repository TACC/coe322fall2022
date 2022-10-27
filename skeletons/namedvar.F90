!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** namedvar.F90 : type with name field handling
!***
!****************************************************************

Program NamedVar
  implicit none

  type var
     character(len=20) :: id
     integer :: value
  end type var
  type(var) :: x,y,z,a

  x = var("x", 1 )
  print *,x
  y = var("y", 2 )
  print *,y
  z = varadd(x,y)
  print *,z
  a = varmult(z,2)  
  print *,a

contains
  
end Program NamedVar

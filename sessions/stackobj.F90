Module CharacterStuff

  type var
     character :: id = "." 
     character(len=20) :: expression
     integer :: value
  end type var

!  interface operator(+)
!        ...... varadd

contains
  integer function char_to_int(char)
    implicit none
    character,intent(in) :: char
    char_to_int = iachar(char)-iachar("0")
  end function char_to_int

  logical function isdigit(char)
    implicit none
    character,intent(in) :: char
    integer :: code,code_0,code_9

    code = iachar(char)
    code_0 = iachar("0")
    code_9 = iachar("9")
    isdigit = code.ge.code_0 .and. code.le.code_9
  end function isdigit

  logical function islower(char)
    implicit none
    character,intent(in) :: char
    integer :: code,code_a,code_z

    code = iachar(char)
    code_a = iachar("a")
    code_z = iachar("z")
    islower = code.ge.code_a .and. code.le.code_z

  end function islower

End Module CharacterStuff

Module StackStuff
  use CharacterStuff
  implicit none

  type stack
     type(var),dimension(10) :: data
     integer :: top = 0
   contains
     procedure,public :: printme,push
  end type stack

  contains
    subroutine printme(me)
      implicit none
      class(stack) :: me
      integer :: i
      print *,( me%data(i),"; ",i=1,me%top )
    end subroutine printme
    subroutine push(me,char)
      implicit none
      class(stack) :: me
      character,intent(in) :: char
      integer :: value 
      value = char_to_int(char)
      print *,"Value: ",value
      me%top = me%top + 1
      me%data(me%top)%value = value
    end subroutine push
    subroutine operate(....)
      if .... is a plus ....
         ! with the homework for today
         call varadd(stack(top-1),stack(top))
         ! for next week: operator overloading
         stack(top-1) + stack(top)
    end subroutine operate
End Module StackStuff

Program lowerchar
  use CharacterStuff
  use StackStuff
  implicit none
  character :: char

  !  type(var),dimension(10) :: thestack
  type(stack) :: thestack
  integer :: i,value

  do 
     ! print *,( thestack(i),"; ",i=1,top )
     call thestack%printme()
     read *,char 
     if (char=="0") exit
     if ( islower(char) ) then
        ! name the top with this character
        ! thestack(top)%id = char
        call thestack%name_top(char)
     else if ( isdigit(char) ) then
        ! push this number onto the stack
        call thestack%push(char)
     else if ( isoperator(char) ) then
        call thestack%operate(char)
     else
        print *,char,"is something else"
     end if
  end do

End Program lowerchar

!! ESC % : query replace

!! Ctrl-<space> 
!! goto other end
!! ESC w : scoop up
!! goto destination
!! Ctrl-y : paste

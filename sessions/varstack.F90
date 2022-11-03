Module CharacterStuff

  type var
     character :: id = "." 
     character(len=20) :: expression
     integer :: value
  end type var

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

  type(var),dimension(10) :: vars
  integer :: top = 0
End Module StackStuff

Program lowerchar
  use CharacterStuff
  use StackStuff
  implicit none
  character :: char

  !  type(var),dimension(10) :: vars
  integer :: i,value

  do 
     print *,( vars(i),"; ",i=1,top )
     read *,char 
     if (char=="0") exit
     if ( islower(char) ) then
        ! name the top with this character
        vars(top)%id = char
     else if ( isdigit(char) ) then
        ! create var in the vars array
        ! increase top
        top = top + 1
        ! put number in the top var
        value = char_to_int(char)
        print *,"Value: ",value
        vars(top)%value = value
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

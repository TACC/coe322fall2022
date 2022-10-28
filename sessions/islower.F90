Program lowerchar
  implicit none
  character :: char

  char = "a"
  print '(a)',char
  print *,"a:",islower(char)
  char = "T"
  print *,"T:",islower(char)

contains 
  logical function islower(char)
    implicit none
    character,intent(in) :: char
    integer :: code,code_a,code_z

    code = iachar(char)
    code_a = iachar("a")
    code_z = iachar("z")
    islower = code.ge.code_a .and. code.le.code_z

  end function islower
End Program lowerchar

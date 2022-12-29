# BlockLine
single file programming language for beginers ( made in c++ )

## TO BUILD:
you need to have clang and nothing more, and then you execute `build.bat` or `build.sh` ( depends if you use Windows or Linux )
or you can use the release builds that are already compiled

## TO RUN A PROGRAMM
only need to execute `blockline.exe` ( in linux you need to open the terminal and run `blockline` )
the default main file always is `Main.block`, so, as long as you have that and `Project.block` for
configurations, you are good to go

## STRUCTURE OF A BLOCKLINE PROJECT ( the BlockLine file extension is block ):
the structure is:
`Main.block`
`Project.block`
`AnythingElse.block`
inside `Main.block` you have the entry point of your programm
in `Project.block` you have the block files to import

## IMPORTING FILES
to import something you need to add this to your Project.block`
import --file--.block --macro--`
and to use the file in your code you need to do this on Main.block
`execute --macro--`

## VARIABLES
you define variables with this two ways:
`var --name-- --value--` for private variables
`global --name-- --value--` for global variables

## COMANDS
set --variable-- --value/variable--                sets a variable
sum --variable-- --value/variable--                adds a variable
sub --variable-- --value/variable--                substract a variable
mul --variable-- --value/variable--                multiply a variable
div --variable-- --value/variable--                divide a variable
jump --line--                                      jump to a line in code
lump --line-- --variable-- --value/variable--      jump to a line in code if the value of a variable is minor than other value
gump --line-- --variable-- --value/variable--      jump to a line in code if the value of a variable is greater than other value 
eump --line-- --variable-- --value/variable--      jump to a line in code if the value of a variable is equal to other value
input --variable--                                 ask to the user to input a value and writes it into a variable
print --text/variable--                            prints something into the scree (spaces are "_" and you can put as much variables/text as you want )
exit --exit code--                                 exits the programm or script

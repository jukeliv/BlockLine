# BlockLine
single file programming language for beginners ( made in c++ )

## COMPILING BLOCKLINE:
you need to have a C++ compiler and Make,
then you need to open a Terminal window and run "make"
the make file is pre configured and the process should be straight
NOTE if the C++ compiler that you have is not clang, you need to tell to the make file
by writing `make CXX=g++` ( this is the example for gcc, just put your compiler in there and it should work )
also, if you are in windows, you need to add `OS=Win`to the compiler flags

## RUN A PROGRAM
only need to execute `blockline.exe` ( in linux you need to open the terminal and run `blockline` )
the default main file always is `Main.block`, so, as long as you have that and `Project.block` for
configurations, you are good to go

## STRUCTURE OF A BLOCKLINE PROJECT ( the BlockLine file extension is block ):
the structure is:
`--ENTRY_POINT--.block`
`--SUPPORT_SCRIPTS--.block`
`Project.block`
in `Project.block` you can configure your files, add your entry point, import your scripts

## IMPORTING FILES
first you need to set your entry point, by writing
`entry --file--.block`
the, to import something ( like extra BlockLine scripts ) you need to add this to your `Project.block`
`import --file--.block --macro--`
and to use the file in your code you need to do this on a SCRIPT.block
`execute --macro--`

## VARIABLES
you define variables with this two ways:
`var --name-- --value--` for private variables
`global --name-- --value--` for global variables

## COMMANDS
`set --variable-- --value/variable--`                sets a variable
`sum --variable-- --value/variable--`                adds a variable
`sub --variable-- --value/variable--`                subtract a variable
`mul --variable-- --value/variable--`                multiply a variable
`div --variable-- --value/variable--`                divide a variable
`jump --line--`                                      jump to a line in code
`lump --line-- --variable-- --value/variable--`      jump to a line in code if the value of a variable is minor than other value
`gump --line-- --variable-- --value/variable--`      jump to a line in code if the value of a variable is greater than other value 
`eump --line-- --variable-- --value/variable--`      jump to a line in code if the value of a variable is equal to other value
`input --variable--`                                 ask to the user to input a value and writes it into a variable
`print --text/variable--`                            prints something into the scree (spaces are "_" and you can put as much variables/text as you want )
`exit --exit code--`                                 exits the program or script

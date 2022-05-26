
/*Name:Kamal Karkidholi
  Student id: 1001514809
  CSE-3320-001
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <limits.h>

int main(void) {
    pid_t child;
    DIR * d;
    struct dirent * de;
    int i, c, k;
 //maximum size
    char s[256], cmd[256], file[1024], dir[2048] ;
    time_t t;

    while (1) {

      t = time( NULL );
   // To show the system time and date from system call
      printf( "Time: %s\n", ctime( &t ));
      printf("-----------------------------------------------\n" );

      getcwd(s, 200);
    //It displays the current working directories
      printf( "\nCurrent Working Directory: %s \n", s);

      d = opendir( "." );
      c = 0;
      while ((de = readdir(d))){
          if ((de->d_type) & DT_DIR) 
       //It shows the list of directories under the current directory
             printf( " ( %d Directory:  %s ) \n", c++, de->d_name);	  
      }
      closedir( d );
      printf( "-----------------------------------------\n" );
    //'.' is current working directory
    // '..' is parent directory
      d = opendir( "." );
      c = 0;                    
      while ((de = readdir(d))){                    
          if (((de->d_type) & DT_REG))   
       // It shows the number of files in the current working directory                           
             printf( " ( %d File:  %s ) \n", c++, de->d_name);
          if ( ( c % 5 ) == 0 ) {
             printf( "Hit n for Next\n" );
             printf("Hit e for Edit File\n");
             printf("Hit r for run directory\n");
             printf("Hit c for changing directory\n");
             printf("Enter s for sort directory by name\n");
             printf("Enter m for moving file from one directory to antother\n");
             printf("Enter z for remove directory\n");
             printf("Enter q for exit\n");
             k = getchar( );}
          

      }
      closedir( d );
      printf( "-----------------------------------------\n" );
  
      c = getchar( ); getchar( );
      switch (c) {
        /* quit the csorturrent working directory/file */
        case 'q': exit(0); 

        /*for renaming a filename*/
        case 'e': printf( "Edit a file name:" ); 
                  scanf( "%s", s );
                  strcpy( cmd, "pico ");
                  strcat( cmd, s );
                  system( cmd );
                  break;
         /*Run the user selected file*/
        case 'r': printf( "Run the selected file/directory:" ); 
                  scanf( "%s", cmd );
                  system( cmd );
                  break;
        /*It allows the user to choose the directory to change */
        case 'c': printf( "Change to sub/parent directory:" );
                  scanf( "%s", cmd );
                  chdir( cmd );   
                  break; 
       /* It allows the user to sort the directories by name alphabetically*/ 
        case 's': printf("Sorting the directory");
                  scanf("%s", cmd);
                             
                  break;
       /* For removing the user entered directory */
       case 'z':printf("Enter the directory name to remove");
                 scanf("%s", cmd);
                 rmdir(cmd);
                 break;
      case 'm':printf("Enter the directory to move the files to other directory");
              scanf("%s", cmd);
           //   mkdir(cmd,d);
             // mv(cmd,name)
       
      }
       
    }
}


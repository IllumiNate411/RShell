#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "executable.hpp"
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

class test : public executable {
	protected:
		const char** argList;
	public:
		test(const char** input) : executable() {
			
			argList = new const char*[5];
			for (unsigned i = 0; i < 5; ++i) {
				argList[i] = input[i];
			}
		}

		~test() {
			delete [] argList;
		}

		virtual bool execute() {
			struct stat sb;
			int status = stat(argList[2], &sb);
			switch(sb.st_mode & S_IFMT){
				case S_IFDIR: if(strcmp(argList[1],"-d")==0 || strcmp(argList[1], "-e") == 0){
						      printf("(True)\n");
						      return true;
					      } 
					      else if(strcmp(argList[1], "-f")==0)
					      {
						      cout<<"(False)\n";
						      return false;
					      } 
					      break;
				case S_IFREG: if(strcmp(argList[1], "-f")==0 || strcmp(argList[1], "-e")==0){printf("(True)\n"); return true; } else{cout<<"(False)\n"; return false;} break;
				default: printf("(False)\n"); return false; break;
			}
		}

		virtual string getType() {
			return "exp";
		}
};
#endif

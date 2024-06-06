#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <regex.h>
#include <fnmatch.h>
#include <locale.h>
#include <glob.h>
#include <sys/stat.h>
#include "shell.h"


int has_glob_chars(char *p, size_t len)
{
    char *p2 = p+len;
    char ob = 0, cb = 0;    
    while(p < p2 && *p)
    {
        switch(*p)
        {
            case '*':
            case '?':
                return 1;
                
            case '[':
                ob++;
                break;
                
            case ']':
                cb++;
                break;
        }
        p++;
    }
    
    if(ob && ob == cb)
    {
        return 1;
    }
    return 0;
}

int match_prefix(char *pattern, char *str, int longest)
{
    if(!pattern || !str)
    {
        return 0;
    }
    char *s = str+1;
    char  c = *s;
    char *smatch = NULL;
    char *lmatch = NULL;
    while(c)
    {
        *s = '\0';
        if(fnmatch(pattern, str, 0) == 0)
        {
            if(!smatch)
            {
                if(!longest)
                {
                    *s = c;
                    return s-str;
                }
                smatch = s;
            }
            lmatch = s;
        }
        *s = c;
        c = *(++s);
    }
    
    if(lmatch)
    {
        return lmatch-str;
    }
    if(smatch)
    {
        return smatch-str;
    }
    return 0;
}

int match_suffix(char *pattern, char *str, int longest)
{
    if(!pattern || !str)
    {
        return 0;
    }
    char *s = str+strlen(str)-1;
    char *smatch = NULL;
    char *lmatch = NULL;
    while(s > str)
    {
        if(fnmatch(pattern, str, 0) == 0)
        {
            if(!smatch)
            {
                if(!longest)
                {
                    return s-str;
                }
                smatch = s;
            }
            lmatch = s;
        }
        s--;
    }
    
    if(lmatch)
    {
        return lmatch-str;
    }
    if(smatch)
    {
        return smatch-str;
    }
    return 0;
}

char **get_filename_matches(char *pattern, glob_t *matches)
{
    
    matches->gl_pathc = 0;
    matches->gl_pathv = NULL;

    if(!pattern)
    {
        return NULL;
    }

    
    int res = glob(pattern, 0, NULL, matches);

    
    if(res != 0)
    {
        globfree(matches);
        return NULL;
    }

    return matches->gl_pathv;
}

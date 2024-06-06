#include <stdlib.h>
#include <string.h>
#include "shell.h"

char *strchr_any(char *string, char *chars)
{
    if(!string || !chars)
    {
        return NULL;
    }
    char *s = string;
    while(*s)
    {
        char *c = chars;
        while(*c)
        {
            if(*s == *c)
            {
                return s;
            }
            c++;
        }
        s++;
    }
    return NULL;
}

char *quote_val(char *val, int add_quotes)
{
    char *res = NULL;
    size_t len;
    
    if(!val || !*val)
    {
        len = add_quotes ? 3 : 1;
        res = malloc(len);
        if(!res)
        {
            return NULL;
        }
        strcpy(res, add_quotes ? "\"\"" : "");
        return res;
    }
    
    len = 0;
    char *v = val, *p;
    while(*v)
    {
        switch(*v)
        {
            case '\\':
            case  '`':
            case  '$':
            case  '"':
                len++;
                break;
        }
        v++;
    }
    len += strlen(val);
    
    if(add_quotes)
    {
        len += 2;
    }
    
    res = malloc(len+1);
    if(!res)
    {
        return NULL;
    }
    p = res;
    
    if(add_quotes)
    {
        *p++ = '"';
    }
    
    v = val;
    while(*v)
    {
        switch(*v)
        {
            case '\\':
            case  '`':
            case  '$':
            case  '"':
                
                *p++ = '\\';
                
                *p++ = *v++;
                break;

            default:
                
                *p++ = *v++;
                break;
        }
    }
    
    if(add_quotes)
    {
        *p++ = '"';
    }
    *p = '\0';
    return res;
}

int check_buffer_bounds(int *count, int *len, char ***buf)
{
    if(*count >= *len)
    {
        if(!(*buf))
        {
            
            *buf = malloc(32*sizeof(char **));
            if(!(*buf))
            {
                return 0;
            }
            *len = 32;
        }
        else
        {
            
            int newlen = (*len) * 2;
            char **hn2 = realloc(*buf, newlen*sizeof(char **));
            if(!hn2)
            {
                return 0;
            }
            *buf = hn2;
            *len = newlen;
        }
    }
    return 1;
}

void free_buffer(int len, char **buf)
{
    if(!len)
    {
        return;
    }
    
    while(len--)
    {
        free(buf[len]);
    }
    free(buf);
}

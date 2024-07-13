#ifndef __PARSER_H__
#define __PARSER_H__

#include "command.h"

typedef struct
{

} Parser;

void
parser_init(Parser *parser);

Command
parser_parse(Parser *parser, char *cmd_str);

void
parser_deinit(Parser *parser);

#endif /* __PARSER_H__ */
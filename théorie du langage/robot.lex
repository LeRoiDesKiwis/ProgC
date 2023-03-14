entier [\-|\+]?[0-9]+
flottant [\-|\+]?[0-9]+\.[0-9]+

%%
[ \n	]	
[--].*	{printf("Commentaire ");}
(?i:avance)[ ]	{printf("Avance ");}
(?i:gauche)[ ]	{printf("Gauche ");}
(?i:nom)	{printf("Nom ");}
.	

#ifndef OP_ALL_GENERIC_COMMENT_H
#define OP_ALL_GENERIC_COMMENT_H

#include<map>
#include<string>

#include "op.h"
#include "listtargetcommentitem.h"
#include "listtarget.h"
//struct ListTargetCommentItem ;
struct Target ;
struct Documentation ;

// REMARQUE IMPORTANTE : cette classe augmente la liste ListTarget du projet. Cette liste est passée en paramètre au niveau du constructeur.


struct OpAllGenericComment : Op {
    OpAllGenericComment( Documentation* pp) { pproject = pp ; }
    virtual ~OpAllGenericComment() {}
    virtual void operator()( PageComment* page ) ;

    Documentation* pproject ; // Pourquoi faire cela ? Pour générer les pages web des objects génériques, on a besoin de récupérer le nom des objets spécialisés et certaines de leurs propriétés. Donc on est obligé de reparcourir tout le projet pour les obtenir.
};

#endif


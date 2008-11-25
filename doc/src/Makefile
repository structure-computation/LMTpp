

#CFLAGS= -O2 -fomit-frame-pointer -Wall -pipe -funroll-loops -fno-inline -mcpu=athlon-xp -DCPU=athlon-xp
CFLAGS= -O2


OBJS=  token.o util2html.o opdisplay.o target.o comment.o commentitem.o commentitemtxt.o commentitemkeyword.o commentitemcode.o commentitemsection.o  commentitemtable.o commentitemlist.o commentitemwebpage.o commentitemtutorial.o commentitemexample.o main.o pagecomment.o bloc.o classe.o parameter.o templateparameter.o function.o struct.o typedef.o tagcomment.o visitorbloc.o ophtml.o opdebug.o documentation.o opallclass.o  visitorbloc_getcaracteristicclass.o visitorbloc_getcaracteristicstruct.o visitorbloc_getcaracteristicfunction.o visitorcommentitem.o names.o visitorcommentitem_tohtml.o commentitemgenericcomment.o  listtarget.o visitorcommentitem_listtarget.o opstructure_site.o visitorbloc_setpath_html.o visitorbloc_allclass_tohtml.o opallexample.o visitorcommentitem_setpath_html.o visitorcommentitem_example_tohtml.o visitorcommentitem_is_extuge.o opalltutorial.o visitorcommentitem_tutorial_tohtml.o visitorcommentitem_genericcomment_tohtml.o opgetbrief_for_principalname.o visitorcommentitem_getbrief.o visitorcommentitem_getbrief_of_extuge.o listtargetcommentitem.o visitorbloc_what_type.o opgetbrief_for_name.o visitorcommentitem_webpage_tohtml.o opallitemwebpage.o visitorcommentitem_webpage_exists.o opwebpage_exists.o commentitemlatex.o visitorcommentitem_getkeyword_of_extuge.o opget_listkeyword.o visitorbloc_get_listkeyword.o  commentitemverbatim.o opallgenericcomment2html.o listparameter.o visitorbloc_getsignature.o target_type_without_genericcomment.o visitorcommentitem_is_internal.o opinternal.o

all: main
clean: rm -f  *.o

main: $(OBJS)
	g++ $(OBJS) -lm -o main
	# cd ../..;./doc/src/main . doc

token.o: token.cpp
opdisplay.o: opdisplay.cpp
comment.o: comment.cpp
commentitem.o: commentitem.cpp
commentitemtxt.o: commentitemtxt.cpp
commentitemkeyword.o: commentitemkeyword.cpp
commentitemcode.o: commentitemcode.cpp
commentitemsection.o: commentitemsection.cpp
commentitemtable.o: commentitemtable.cpp
commentitemlist.o: commentitemlist.cpp
commentitemwebpage.o: commentitemwebpage.cpp
main.o: main.cpp
bloc.o : bloc.cpp
classe.o: classe.cpp
struct.o: struct.cpp
parameter.o: parameter.cpp
templateparameter.o: templateparameter.cpp
function.o: function.cpp
typedef.o: typedef.cpp
pagecomment.o: pagecomment.cpp
tagcomment.o: tagcomment.cpp
visitorbloc.o: visitorbloc.cpp
ophtml.o: ophtml.cpp
opdebug.o: opdebug.cpp
documentation.o: documentation.cpp
#visitorbloc_namebaseclass.o: visitorbloc_namebaseclass.cpp
#visitorbloc_namebaseisoledfunction.o: visitorbloc_namebaseisoledfunction.cpp
opallclass.o: opallclass.cpp
visitorbloc_allclass.o: visitorbloc_allclass.cpp
util2html.o: util2html.cpp
#visitorbloc_getcaractesticclass.o: visitorbloc_getcaractesticclass.cpp
#visitorbloc_getcaractesticstruct.o: visitorbloc_getcaractesticstruct.cpp
#visitorbloc_getcaracteristicfunction.o: visitorbloc_getcaracteristicfunction.cpp
visitorcommentitem.o: visitorcommentitem.cpp
#visitorcommentitem_is_example_tutorial.o: visitorcommentitem_is_example_tutorial.cpp
names.o: names.cpp
visitorcommentitem_tohtml.o: visitorcommentitem_tohtml.cpp
#link.o: link.cpp
#listlink.o: listlink.cpp
commentitemgenericcomment.o: commentitemgenericcomment.cpp
commentitemtutorial.o: commentitemtutorial.cpp
commentitemexample.o: commentitemexample.cpp
target.o: target.cpp
listtarget.o: listtarget.cpp
#oplisttarget.o: oplisttarget.cpp
visitorcommentitem_listtarget.o: visitorcommentitem_listtarget.cpp
opstructure_site.o: opstructure_site.cpp
visitorbloc_setpath_html.o: visitorbloc_setpath_html.cpp
visitorbloc_allclass_tohtml.o: visitorbloc_allclass_tohtml.cpp
opallexample.o: opallexample.cpp
visitorcommentitem_setpath_html.o: visitorcommentitem_setpath_html.cpp
visitorcommentitem_example_tohtml.o: visitorcommentitem_example_tohtml.cpp
visitorcommentitem_is_extuge.o: visitorcommentitem_is_extuge.cpp
opalltutorial.o: opalltutorial.cpp
visitorcommentitem_tutorial_tohtml.o: visitorcommentitem_tutorial_tohtml.cpp
visitorcommentitem_genericcomment_tohtml.o: visitorcommentitem_genericcomment_tohtml.cpp
#opallgenericcomment.o: opallgenericcomment.cpp
opgetbrief_for_principalname.o: opgetbrief_for_principalname.cpp
visitorcommentitem_getbrief.o: visitorcommentitem_getbrief.cpp
visitorcommentitem_getbrief_of_extuge.o: visitorcommentitem_getbrief_of_extuge.cpp
listtargetcommentitem.o: listtargetcommentitem.cpp
#opgettype_for_principalname.o: opgettype_for_principalname.cpp
visitorbloc_what_type.o: visitorbloc_what_type.cpp
opgetbrief_for_name.o: opgetbrief_for_name.cpp
visitorcommentitem_webpage_tohtml.o: visitorcommentitem_webpage_tohtml.cpp
opallitemwebpage.o: opallitemwebpage.cpp
visitorcommentitem_webpage_exists.o: visitorcommentitem_webpage_exists.cpp
opwebpage_exists.o: opwebpage_exists.cpp
commentitemlatex.o: commentitemlatex.cpp
visitorcommentitem_getkeyword_of_extuge.o: visitorcommentitem_getkeyword_of_extuge.cpp
opget_listkeyword.o: opget_listkeyword.cpp
visitorbloc_get_listkeyword.o: visitorbloc_get_listkeyword.cpp
#visitorcommentitem_is_ge.o: visitorcommentitem_is_ge.cpp
commentitemverbatim.o: commentitemverbatim.cpp
opallgenericcomment2html.o: opallgenericcomment2html.cpp
listparameter.o: listparameter.cpp
visitorbloc_getsignature.o: visitorbloc_getsignature.cpp
target_type_without_genericcomment.o: target_type_without_genericcomment.cpp
visitorcommentitem_is_internal.: visitorcommentitem_is_internal.cpp
opinternal.o: opinternal.cpp

.cpp.o:
	g++ $(CFLAGS) -c $*.cpp -o $*.o

clean: rm   *.o

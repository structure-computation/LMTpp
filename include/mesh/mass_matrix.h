
using namespace LMT;

/*! 
\author Federica Daghia <daghia@lmt.ens-cachan.fr>

Fonction pour calculer la matrice des masses elementaires pour un element
Elle prend comme arguments:
    * l'element (const),
    * la matrice des masses (attention - elle est reinitialisee a zero au debut),
    * la dimension du probleme
On suppose que tous les ddl sont interpoles avec les memes fonctions de forme

\keyword Maillage/Elément
*/
template<class TE, class TMA>
void create_mass_matrix(const TE &e, TMA &mass_mat, const unsigned &dim){
	// generalisation pour le type d'element
	typedef typename TE::NameElem Name;
		
	// definition de la taille de la matrice de masse et initialisation a zero
	mass_mat.resize(Name::nb_nodes*dim);
	mass_mat.clear();

	// matrice de masse pour un ddl - taille et initialisation a zero 
	TMA mass_mat_single;
	mass_mat_single.resize(Name::nb_nodes);
	mass_mat_single.clear();

	const double *pg = gauss_point_for_order (6, Name() ); // on met un ordre eleve, si l'element est distordu l'integration ne sera pas exacte dans tous les cas
	// dimr est la dimension de l'espace de reference de l'element (e.g. 1 pour un bar, 2 pour un quad...)
	static const int dimr = Name::nb_var_inter;
	static const int step = 1+dimr;

	//boucle sur les points de Gauss - s'arrete quand il trouve un poids egal a 0 (c'est la structure du tableau)
	double poids = 1;
	double det_jac;
	for (unsigned i=0; poids > 0; i++){
		poids = pg[step*i];
		Vec<double, dimr> p;
		for (unsigned j=0; j < dimr; j++){
			p[j] = pg[step*i+j+1]; 	
		};
		Vec<double, Name::nb_nodes> res;
		Mat<double> res1 (1,4,0.);
		get_shape_functions(Name(), p, res);
		res1.row(0) = res; // on met res dans une matrice pour pouvoir en faire la transpose
			
		det_jac = get_det_jac(e, p);
		
		mass_mat_single = mass_mat_single + poids * det_jac * trans(res1) * res1;
	};

	Vec<double > Vassign;
	for (int i=0; i<Name::nb_nodes; i++){
		Vassign.push_back(i*dim);
	};

	for (unsigned j = 0; j<dim; j++){
		mass_mat[Vassign] = mass_mat_single;
		Vassign +=1;
	};	
};

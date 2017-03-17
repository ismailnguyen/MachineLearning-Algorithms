    template < typename LinearOperator, typename HilbertSpaceX,
	typename HilbertSpaceB, typename Preconditioner, typename Iteration >
	typedef typename graph_traits<Graph>::vertex_descriptor VERTEX;
    typedef typename graph_traits<Graph>::vertices_size_type SIZE;
    SIZE dist[num_vertices(g)];

extern "C"
{
		int cg(const LinearOperator& A, HilbertSpaceX& x, const HilbertSpaceB& b,
			const Preconditioner& M, Iteration& iter)
	{
		typedef typename mtl::Collection<Vector>::value_type Scalar;
		Scalar rho(0), rho_1(0), alpha(0), beta(0);
		HilbertSpaceX p(size(x)), q(size(x)), r(b − A*x), z(size(x));
		while (!iter.finished(r)) {
			z = solve(M, r); rho = dot(r, z);
			if (iter.first())
				p = z;
			else {
				beta = rho / rho_1; p = z + beta * p;
			}
			q = A * p; alpha = rho / dot(p, q);
			x += alpha * p; r − = alpha * q;
			rho_1 = rho; ++iter;
		}
		return iter;
	}
}
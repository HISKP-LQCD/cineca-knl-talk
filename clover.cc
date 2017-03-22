void full_clover_term(InstVector& ivector,FVec in_spinor[4][3][2],bool face,std::string mask)
{
  for(int block=0; block!=2; ++block) {

    PrefetchL1FullCloverFullBlockIn(ivector, clBase, clOffs, block);
    LoadFullCloverFullBlock(ivector, clov_full, clBase, clOffs, block);

    for(int sc1=0; sc1!=6; ++sc1) { // half-spin-colour row

      // Calculate out indices
      FVec *clout  = out_spinor[spin_out][col_out];

      for(int sc2=0; sc2!=6; ++sc2) { // half-spin-colour column

        // Calculate in indices
        FVec *clin  = in_spinor[spin_in][col_in];

        if(sc2 == 0 && !face)   mulCVec(ivector,clout,clov_full[sc1][sc2],clin,mask);
        else                  fmaddCVec(ivector,clout,clov_full[sc1][sc2],clin,clout,mask);
      }
    }
  }
}

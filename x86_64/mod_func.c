#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;

extern void _cadyn_reg(void);
extern void _capool_reg(void);
extern void _cas_reg(void);
extern void _cat_reg(void);
extern void _currentclamp_reg(void);
extern void _h_reg(void);
extern void _im_reg(void);
extern void _ka_reg(void);
extern void _kaprox_reg(void);
extern void _kca_reg(void);
extern void _kdrca1_reg(void);
extern void _leak_reg(void);
extern void _na3_reg(void);
extern void _nap_reg(void);
extern void _netstimNEWh_reg(void);
extern void _netstimNEWp_reg(void);
extern void _netstimNEWpud_reg(void);
extern void _sahp_reg(void);

void modl_reg(){
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");

    fprintf(stderr," cadyn.mod");
    fprintf(stderr," capool.mod");
    fprintf(stderr," cas.mod");
    fprintf(stderr," cat.mod");
    fprintf(stderr," currentclamp.mod");
    fprintf(stderr," h.mod");
    fprintf(stderr," im.mod");
    fprintf(stderr," ka.mod");
    fprintf(stderr," kaprox.mod");
    fprintf(stderr," kca.mod");
    fprintf(stderr," kdrca1.mod");
    fprintf(stderr," leak.mod");
    fprintf(stderr," na3.mod");
    fprintf(stderr," nap.mod");
    fprintf(stderr," netstimNEWh.mod");
    fprintf(stderr," netstimNEWp.mod");
    fprintf(stderr," netstimNEWpud.mod");
    fprintf(stderr," sahp.mod");
    fprintf(stderr, "\n");
  }
  _cadyn_reg();
  _capool_reg();
  _cas_reg();
  _cat_reg();
  _currentclamp_reg();
  _h_reg();
  _im_reg();
  _ka_reg();
  _kaprox_reg();
  _kca_reg();
  _kdrca1_reg();
  _leak_reg();
  _na3_reg();
  _nap_reg();
  _netstimNEWh_reg();
  _netstimNEWp_reg();
  _netstimNEWpud_reg();
  _sahp_reg();
}

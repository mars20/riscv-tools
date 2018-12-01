require_extension('V');
require_rv64;
vreg_t vect;
vect.e32[0] = RS1;
WRITE_VRD(v_bcast(vect, EW, VL));

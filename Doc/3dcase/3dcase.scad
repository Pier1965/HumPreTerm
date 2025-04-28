// dimensioni interne
// 64x68x20
ri = 3;			// raggio di raccordo interno
sp = 4;			// spessore parete
re = ri+sp;		// rr esterno
b = 64;			// base
h = 68;			// altezza
dp = 20;		// profondita
$fn=50;
//
difference(){
translate([ri+sp,ri+sp,0])
minkowski(){
cylinder(h=(dp+sp)/2,r=re);
cube([b+2*sp-2*re,h+2*sp-2*re,(dp+sp)/2]);
}
// parte da sottrarre
// interna
translate([ri+sp,ri+sp,sp])
minkowski(){
cylinder(h=(dp+1)/2,r=ri);
//
cube([b-2*ri,h-2*ri,(dp+1)/2]);
}
// dentino
translate([ri+sp/2+sp/2,ri+sp/2+sp/2,sp+dp-sp/2])
minkowski(){
cylinder(h=(sp+1)/2,r=ri+sp/2);
//
cube([b+sp-2*(ri+sp/2),h+sp-2*(ri+sp/2),(sp+1)/2]);
}
}
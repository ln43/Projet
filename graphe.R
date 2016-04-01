rm(list=ls())

d=read.table("data1sM.txt",col.names=c("T","Ainit","Etat"),header=T)

etat <- factor(d$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(d$"T", d$"Ainit", pch = 19,col = mescouleurs[etat], main="Diagramme Transition Sans Mutation",xlab="T",ylab="Ainit")
legend("topright", inset = 0.02, pch = 19, legend = c("extinction","exclusion","cohabitation"), col = mescouleurs)

#_ _ _ _ _ _ _


dmut=read.table("VFmut.txt",col.names=c("T","Ainit","Etat"),header=T)

etat <- factor(dmut$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(dmut$"T", dmut$"Ainit", pch = 19, col = mescouleurs[etat], main="Diagramme Transition Avec Mutation",xlab="T",ylab="Ainit")
legend("topright", inset = 0.02, pch = 19, legend = c("extinction","cohabitation"), col = mescouleurs)

#_ _ _ _ _ _ _
#install.packages("rgl")
dess=read.table("Essai.txt",col.names=c("T","Ainit","D","Etat"),header=T)

#View 1
etat <- factor(dess$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot3d(dess$"T", dess$"Ainit", dess$"D", pch = 24, cex=1,col = mescouleurs[etat], main="Diagramme Transition Avec Mutation",xlab="T",ylab="Ainit")
legend("topright", inset = 0.02, pch = 19, legend = levels(etat), col = mescouleurs)

#View 2
par(mfrow=c(3,4))

for(i in levels(factor(dess$"D"))){
  etat <- factor(dess$"Etat"[dess$"D"==i])
  mescouleurs <- rainbow(length(levels(etat)))
  plot(dess$"T"[dess$"D"==i], dess$"Ainit"[dess$"D"==i], pch = 19, col = mescouleurs[etat], main=paste("D = ",i),xlab="T",ylab="Ainit")
}
plot(1, type="n", axes=F, xlab="", ylab="",main="Transition de phase \n sans mutation")
legend("topright", inset = 0.02, pch = 19, legend = c("extinction","cohabitation"), col = mescouleurs)

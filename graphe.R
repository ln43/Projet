rm(list=ls())

d=read.table("data500.txt",col.names=c("T","Ainit","Etat"),header=T)

#View3
etat <- factor(d$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(d$"T", d$"Ainit", pch = 20, col = mescouleurs[etat])
legend("topleft", inset = 0.02, pch = 19, legend = levels(etat), col = mescouleurs)

#View 1
library(car) 
scatterplot(Ainit ~ T | Etat, data=d,
            xlab="T", ylab="Ainit",
            main="Simulation") 

#View 2
#install.packages("ggplot2")
library(ggplot2)
p=ggplot(data=d, aes(x=T, y=Ainit, colour=Etat))
p= p + geom_raster(aes(fill = Etat),hjust=0.5,vjust=0.5, interpolate=FALSE)
print(p)

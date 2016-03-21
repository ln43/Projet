rm(list=ls())

d=read.table("data.txt",col.names=c("T","Ainit","Etat"),header=T)


p=ggplot(data=d, aes(x=T, y=Ainit, colour=Etat))
p= p + geom_raster(aes(fill = Etat),hjust=0.5,vjust=0.5, interpolate=FALSE)
print(p)

#install.packages("ggplot2")


// Calculate the intersection of a ray and a cylinder

 Vector oc = {ray.origin.x - cylinder.center.x, ray.origin.y - cylinder.center.y, ray.origin.z - cylinder.center.z};
    double a = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cylinder.normal), 2);
    double b = 2 * (vec_dot(ray.dir, oc) - vec_dot(ray.dir, cylinder.normal) * vec_dot(oc, cylinder.normal));
    double c = vec_dot(oc, oc) - pow(vec_dot(oc, cylinder.normal), 2) - cylinder.radius * cylinder.radius;
    double disc = b * b - 4 * a * c;
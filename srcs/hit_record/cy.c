

// Calculate the intersection of a ray and a cylinder

 Vector oc = {ray.origin.x - cylinder.center.x, ray.origin.y - cylinder.center.y, ray.origin.z - cylinder.center.z};
    double a = vec_dot(ray.direction, ray.direction) - pow(vec_dot(ray.direction, cylinder.normal), 2);
    double b = 2 * (vec_dot(ray.direction, oc) - vec_dot(ray.direction, cylinder.normal) * vec_dot(oc, cylinder.normal));
    double c = vec_dot(oc, oc) - pow(vec_dot(oc, cylinder.normal), 2) - cylinder.radius * cylinder.radius;
    double disc = b * b - 4 * a * c;
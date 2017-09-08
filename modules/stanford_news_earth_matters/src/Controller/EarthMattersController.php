<?php

namespace Drupal\stanford_news_earth_matters\Controller;

use Drupal\Core\Database\Connection;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Routing\CurrentRouteMatch;
use Symfony\Component\DependencyInjection\ContainerInterface;

class EarthMattersController implements ContainerInjectionInterface {

  /** @var \Drupal\Core\Routing\CurrentRouteMatch */
  private $routeMatch;

  /** @var \Drupal\Core\Database\Connection */
  private $database;

  /**
   * {@inheritdoc}
   */
  public function __construct(CurrentRouteMatch $route_match, Connection $database) {
    $this->routeMatch = $route_match;
    $this->database = $database;
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static($container->get('current_route_match'), $container->get('database'));
  }

  /**
   * Get the page contents.
   *
   * @return array|null
   *   Render array for the page.
   */
  public function page() {
    $terms = [];
    /** @var \Drupal\taxonomy\Entity\Term $term */
    foreach ($this->routeMatch->getParameters()->all() as $term) {
      $terms[] = $term->id();
    }
    return $this->getView(implode('+', $terms));
  }

  /**
   * Get the view with the arguments or without.
   *
   * @param string $terms
   *   Term IDs to use as the argument.
   *
   * @return array|null
   *   Render array of the view.
   */
  private function getView($terms) {
    if ($terms) {
      return views_embed_view('earth_matters_listing', 'news_list', $terms);
    }

    return views_embed_view('earth_matters_listing', 'news_list');
  }

}

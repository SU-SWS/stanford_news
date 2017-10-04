<?php

namespace Drupal\stanford_news_earth_matters\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\Core\Database\Connection;
use Drupal\Core\DependencyInjection\ContainerInjectionInterface;
use Drupal\Core\Routing\CurrentRouteMatch;
use Drupal\block_content\Entity\BlockContent;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Symfony\Component\HttpFoundation\RequestStack;

class EarthMattersController extends ControllerBase implements ContainerInjectionInterface {

  /** @var \Drupal\Core\Routing\CurrentRouteMatch */
  private $routeMatch;

  /** @var \Drupal\Core\Database\Connection */
  private $database;

  /** @var \Symfony\Component\HttpFoundation\Request */
  private $currentRequest;

  /**
   * {@inheritdoc}
   */
  public function __construct(CurrentRouteMatch $route_match, Connection $database, RequestStack $request) {
    $this->routeMatch = $route_match;
    $this->database = $database;
    $this->currentRequest = $request->getCurrentRequest();
  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {
    return new static($container->get('current_route_match'), $container->get('database'), $container->get('request_stack'));
  }

  /**
   * Get the page contents.
   *
   * @return mixed
   *   Render array for the page or redirect.
   */
  public function page() {
    $content = [];

    if ($redirect = $this->checkParameters()) {
      return $redirect;
    }

    // Hero Block. Has already been created on production.
    $block = BlockContent::load(26);

    // If we are able to load the block let's get the content into a render [].
    if (!empty($block)) {

      // Render the block with view mode 'full'.
      $block_content = \Drupal::entityTypeManager()
        ->getViewBuilder('block_content')
        ->view($block);

      // Force a few variant settings as the block isn't fully flushed out.
      $variant_settings = &$block_content['#ds_configuration']['layout']['settings']['pattern']['variants'];
      $variant_settings['is_tall']['constant_value'] = 'is-short';
      $variant_settings['is_page_title']['constant_value'] = 0;
      $variant_settings['header_position']['constant_value'] = 'not-centered';

      // Add it all to the render array.
      $content['hero'] = $block_content;
    }

    $terms = [];
    /** @var \Drupal\taxonomy\Entity\Term $term */
    foreach ($this->routeMatch->getParameters()->all() as $term) {
      $terms[] = $term->id();
    }
    $view = $this->getView(implode('+', $terms));

    if (!empty($view)) {
      $content['view'] = $view;
    }

    return $content;
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

  /**
   * If $_GET parameter is used (possibly site crawler) redirect to clean URL.
   *
   * @return null|\Symfony\Component\HttpFoundation\RedirectResponse
   *   The redirect of null if its already clean.
   */
  private function checkParameters() {
    $topics = $this->currentRequest->get('topic');
    if (empty($topics)) {
      return NULL;
    }

    $num_terms = count($topics);

    $args = [];
    $term_number = 1;
    foreach ($topics as $topic) {
      $args["term$term_number"] = $topic;
      $term_number++;
    }

    return $this->redirect("stanford_news_earth_matters.{$num_terms}_terms", $args, [], 301);
  }

}
